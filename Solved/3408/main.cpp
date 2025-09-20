class TaskManager {
public:
    struct Task{
        int userId;
        int taskId;
        int priority;
    };
    TaskManager(vector<vector<int>>& tasks) {
        for(auto task: tasks){
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            //add task to the system
            add(userId, taskId, priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        //add it to the system
        priorityToTaskMap[priority][taskId] = {userId, taskId, priority};
        taskToPriority[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) {
        //grab existing task from the system and remove it
        int priority = taskToPriority[taskId];
        //grab existing task from the system
        Task t;
        t = priorityToTaskMap[priority][taskId];
        //remove existing version
        rmv(taskId);
        //set it's priority to new priority
        t.priority = newPriority;
        //readd it to the system
        add(t.userId, t.taskId, t.priority);
    }
    
    void rmv(int taskId) {
        //grab it's priority listing
        int priority = taskToPriority[taskId];
        //erase it from taskToPriority once it is grabbed
        auto taskTPIt = taskToPriority.find(taskId);
        taskToPriority.erase(taskTPIt);
        //find the task listing in the corresponding priority mapping
        auto taskIt = priorityToTaskMap[priority].find(taskId);
        priorityToTaskMap[priority].erase(taskIt);
        if(priorityToTaskMap[priority].empty()){
            auto priorityIt = priorityToTaskMap.find(priority);
            priorityToTaskMap.erase(priorityIt);
        }
    }
    
    int execTop() {
        //grab id of the top task
        if(priorityToTaskMap.empty()){
            return -1;
        }
        auto it = priorityToTaskMap.begin()->second.begin();
        if(it == priorityToTaskMap.begin()->second.end()){
            return -1;
        }
        int taskId = it->first;
        int userId = it->second.userId;
        rmv(taskId);
        return userId;
    }

private:
    //storing priority as key to map with taskId as key 
    map<int, map<int, Task, std::greater<int>>, std::greater<int>> priorityToTaskMap;
    //stores mapping of taskId to priority in map
    unordered_map<int, int> taskToPriority;
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */