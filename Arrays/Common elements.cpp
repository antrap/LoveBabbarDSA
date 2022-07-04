vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            unordered_map<int,bool> hash1;
            for(int i=0;i<n1;i++){
                hash1[A[i]]=true;
            }
            
            stack<int> s;
            for(int i=0;i<n2;i++){
                if(hash1.find(B[i])!=hash1.end() && hash1[B[i]]==true){
                s.push(B[i]);//common of 1 and 2 are stored
                hash1[B[i]]=false;
                }
            }
            unordered_set<int> hash2;
            for(int i=0;i<n3;i++){
                hash2.insert(C[i]);
            }
            vector<int> ans;
            while(s.empty()==false){
                if(hash2.find(s.top())!=hash2.end()){
                ans.push_back(s.top());
                s.pop();
                }
                else s.pop();
            }
            sort(ans.begin(),ans.end());
            return ans;
        }
