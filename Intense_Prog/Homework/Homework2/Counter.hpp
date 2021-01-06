#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>

template <class T>
class Counter{
  public:

    Counter(){total_count=0;} //constructor
    Counter(std::vector<T> vals){//constructor with vector args
      total_count=0; //set total to zero
      int size = vals.size();
      for(int i=0; i<size; i++){//loop through vector
        mapV[vals[i]] += 1; //add vector element or incriment
        total_count += 1;
      }
    };

    int Count(){return total_count;} // return total counts
    int Count(T key){
      if(mapV.find(key) != mapV.end()){ //find the key element
        typename std::map<T, int>::iterator it;
        for(it = mapV.begin(); it != mapV.end(); it++){ //loop through map
          if(it->first==key){
            return it->second; //return the key element's value
          }
        }
      }
      return 0;
    }

    int Count(T min, T max){ //find the min or max of the set
      int temp_total=0; //create local temp

      typename std::map<T, int>::iterator it;
      for(it = mapV.begin(); it != mapV.end(); it++){ //iterate through map
        if((it->first >= min) && (it->first < max)){
          temp_total += it->second; // add to the total between two values
        }
      }
      return temp_total; //return total in range
    }

    void Remove(T key){ //remove map element
      if(mapV.find(key) != mapV.end()){ //search map for the element
        int tot_remove = mapV.find(key)->second;
        mapV.erase(mapV.find(key));//remove element
        total_count = total_count - tot_remove;//reduce total
      }
    }

    void Increment(T key){ //increment key value by one
      if(mapV.find(key) != mapV.end()){//find key in map
        typename std::map<T, int>::iterator it;
        for(it = mapV.begin(); it != mapV.end(); it++){
          if(it->first==key){
            it->second = it->second+1;//add one to the key's value
          }
        }
      }
      else{
        mapV[key] += 1; //add one to the key
      }
      total_count = total_count+1; //add one to the total count
    }

    void Increment(T key, int n){ //increment key by n amount
      if(mapV.find(key) != mapV.end()){ //find key in map
        typename std::map<T, int>::iterator it;
        for(it = mapV.begin(); it != mapV.end(); it++){
          if(it->first==key){
            it->second = it->second+n; //add n to key value
          }
        }
      }
      else{
        mapV[key] += n;//add n to key
      }
      total_count = total_count+n;//add n to the total count
    }

    void Decrement(T key){//decrement key by 1
      if(mapV.find(key) != mapV.end()){
        typename std::map<T, int>::iterator it;
        for(it = mapV.begin(); it != mapV.end(); it++){
          if(it->first==key){
            if(it->second > 1){
              it->second = it->second-1;
              total_count = total_count-1;
            }
            else{
              Remove(key);
            }
          }
        }
      }
    }

    void Decrement(T key, int n){ //decrement key by n
      if(mapV.find(key) != mapV.end()){
        typename std::map<T, int>::iterator it;
        for(it = mapV.begin(); it != mapV.end(); it++){
          if(it->first==key){
            if(it->second - n > 0){//check if n is greater than the value amount already
              it->second = it->second-n;//subtract n
              total_count = total_count-n;//subtract n from key value
            }
            else{
              Remove(key);//remove from map
            }
          }
        }
      }
    }

    T MostCommon(){//FATAL ERROR
      if(!mapV.empty()){ //
        return this->MostCommon(1)[0];//run most common return the first index
      }
      else{
          std::domain_error("Error, empty counter map"); //domain error throw
          return 0;
      }
    }

    std::vector<T> MostCommon(int n){//find the most common n amount of elements
      std::map<T,int> temp;
      std::vector<T> sol;
      int max_values_returned = n;
      for(std::pair<T, int> pair : mapV){//store map values to temp map
          temp.insert(pair);
      }

      int size = mapV.size();
      if(max_values_returned > size){ //check if n is greater than map.size
        max_values_returned = size;
      }

      for(int i = 0; i<max_values_returned; i++){ //iterate through n
        std::pair<T, int> temp_max;
        for (std::pair<T, int> pair : temp){
          if(pair.second > temp_max.second)
          {
            temp_max = pair; //make pair most common instance
          }
        }
        sol.push_back(temp_max.first); //add most common instance to the solution vector
        if(temp.find(temp_max.first) != temp.end()){ //find if the element exists
          temp.erase(temp.find(temp_max.first)); // erase the temp map element
        }
      }
      return sol;
    }

    T LeastCommon(){//find the least common
      if(!mapV.empty()){
        return this->LeastCommon(1)[0]; //return the first returned index of least common
      }
      else{
          std::domain_error("Error, empty counter map"); //domain error throw
          return 0;
      }
    }

    std::vector<T> LeastCommon(int n){//find least common n amount of elements
      std::map<T,int> temp; //create temp map
      std::vector<T> sol;
      int max_values_returned = n;
      for(std::pair<T, int> pair : mapV){//store map values to temp map
          temp.insert(pair);
      }

      int size = mapV.size();
      if(max_values_returned > size){//checks if n is greater than map size
        max_values_returned = size;
      }

      for(int i = 0; i<max_values_returned; i++){ //fill the solution vector
        std::pair<T, int> temp_min;
        temp_min.second = WINT_MAX; //set int to highest value
        for (std::pair<T, int> pair : temp){
          if(pair.second < temp_min.second)//compare if value is lower
          {
            temp_min = pair; //lowest min of the set
          }
        }
        sol.push_back(temp_min.first); //add the temp value to the solution vector
        if(temp.find(temp_min.first) != temp.end()){
          temp.erase(temp.find(temp_min.first));//erase temporary value in map
        }
      }
      return sol; //return vector
    }

    std::map<T,double> Normalized(){ //turn counts into decimal percents
      std::map<T,double> sol; //solution vector
      std::pair<T,double> temp;
      for(std::pair<T, int> pair : mapV){
          temp.first = pair.first;
          temp.second = (double)pair.second/(double)total_count; //divide the count by the total amount
          sol.insert(temp); //add temp to the
      }
      return sol;
    }

    std::set<T> Keys(){ //return set of keys
      std::set<T> sol;
      for(std::pair<T, int> pair : mapV){
        sol.insert(pair.first); // add key to the solution set
      }
      return sol; //return vector set of key
    }

    std::vector<int> Values(){//return set of values
      std::vector<int> sol;
      for(std::pair<T, int> pair : mapV){
        sol.push_back(pair.second);// add values to the solution set
      }
      return sol;//return vector set of values
    }

    template<typename U> //create template U
    friend std::ostream& operator<<(std::ostream& os, const Counter<U> &b); //instantiate override

  private:
    std::map<T,int> mapV;
    int total_count;
};



template<typename U>
std::ostream& operator<<(std::ostream& os, const Counter<U> &b){ //create override method
  os <<"{"; //add to front
  for (std::pair<U, int> elem : b.mapV){
    os <<elem.first<< ":" <<elem.second<<",";//add elemnts plus comma
  }
  os <<"}"<< std::endl; //add to end of line
  return os;//return print 
}
