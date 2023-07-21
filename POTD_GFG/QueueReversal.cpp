//16/7/23

queue<int> rev(queue<int> q)
    {
        // add code here.
         stack<int> s;

        //step 1: put all elements of q into s
        while(!q.empty() ) {
                int element = q.front();
                q.pop();

                s.push(element);
        }

        //step2: put all element from stackinto q
        while(!s.empty()) {
                int element = s.top();
                s.pop();

                q.push(element);
        }
        
        return q;
        
    }
