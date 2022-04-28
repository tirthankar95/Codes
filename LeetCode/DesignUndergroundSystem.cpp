typedef pair<string,int> si;
typedef pair<double,double> dd;

class UndergroundSystem {
    unordered_map<int,si> checkInMap;
    map<string,dd> isPresent;
public:
    UndergroundSystem() {
        checkInMap.clear();
        isPresent.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id]=si(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t) {
        si getDetails=checkInMap[id];
        string stationKey=getDetails.first+" "+stationName;
        if(isPresent.find(stationKey)!=isPresent.end()){
            //element found.
            dd temp=isPresent[stationKey];
            temp.first++;
            temp.second+=(double)((t-getDetails.second)-temp.second)/temp.first;
            isPresent[stationKey]=temp;
        }
        else{
            //element not found. 
            isPresent[stationKey]=dd(1,t-getDetails.second);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string stationKey=startStation+" "+endStation;
        return isPresent[stationKey].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */