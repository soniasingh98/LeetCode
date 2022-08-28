class Solution {
public: int garbageCollection(vector<string>& garbage, vector<int>& travel) 
{int paperIndex=0,metalIndex=0,glassIndex=0,paper=0,metal=0,glass=0,paperTruck=0,metalTruck=0,glassTruck=0;           
                                                                         for(int i=0;i<garbage.size();i++){
            for(int j=0;j<garbage[i].size();j++){
                if(garbage[i][j]=='P'){
                    paper+=1;
                    paperIndex=i;
                }
                else if(garbage[i][j]=='M'){
                    metal+=1;
                    metalIndex=i;
                }
                else if(garbage[i][j]=='G'){
                    glass+=1;
                    glassIndex=i;
                }
            }
        }   
          if(paper!=0 && paperIndex>0){
            for(int k=0;k<paperIndex;k++){
                paperTruck+=travel[k];
                
            }
          }
            if(metal!=0 && metalIndex>0){
            for(int l=0;l<metalIndex;l++){
                metalTruck+=travel[l];
            }
            }
                                                                                 if(glass!=0 && glassIndex>0){
            for(int m=0;m<glassIndex;m++){
                glassTruck+=travel[m];
            }                                                                     }
 return(paperTruck+paper+metal+metalTruck+glass+glassTruck);
    }
};