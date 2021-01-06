#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include "iostream"

template<class T>
bool sortByCount(const std::pair<T,int> a, const std::pair<T,int> b){
  return (a.second < b.second);
}

template <class T>
class Counter{
  public:
    Counter();
    Counter(std::vector<T> vals);
    int Count()const;
    int Count(const T & key)const;
    int Count(const T & min, const T & max);
    void Remove(const T & key);
    void Increment(const T & key);
    void Increment(const T & key, int n);
    void Decrement(const T & key);
    void Decrement(const T & key, int n);
    T MostCommon()const;
    std::vector<T>MostCommon(const int & n);
    T LeastCommon()const;
    std::vector<T>LeastCommon(int n)const;
    std::map<T,double> Normalized()const;
    std::set<T> Keys()const;
    std::vector<int> Values() const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Counter<U> &b);

  private:
    std::map<T,int> mapV;
};

template <class T>
Counter<T>::Counter(std::vector<T> vals){
  int size = vals.size();
  for(int i=0; i<size; i++){//unsigned int
    mapV[vals[i]] += 1;
  }
};

template <class T>
int Counter<T>::Count()const{
  int total;
  for(std::pair<T, int> pair : mapV){
    total = total + pair->second;
  }

}

template <class T>
int Counter<T>::Count(const T & key)const{
  if(mapV.find(key) != mapV.end()){
    typename std::map<T, int>::iterator it;
    for(it = mapV.begin(); it != mapV.end(); it++){
      if(it->first==key){
        return it->second;
      }
    }
  }
  return 0;
}

template <class T>
int Counter<T>::Count(const T & min, const T & max)const{
  int temp_total=0;

  typename std::map<T, int>::iterator it;
  for(it = mapV.begin(); it != mapV.end(); it++){
    if((it->first >= min) && (it->first < max)){
      temp_total += it->second;
    }
  }
  return temp_total;
}

template <class T>
void Counter<T>::Remove(const T & key) const{
  if(mapV.find(key) != mapV.end()){
    mapV.erase(mapV.find(key));
  }
}

template <class T>
void Counter<T>::Increment(const T & key) const{
  if(mapV.find(key) != mapV.end()){
    typename std::map<T, int>::iterator it;
    for(it = mapV.begin(); it != mapV.end(); it++){
      if(it->first==key){
        it->second = it->second+1;
      }
    }
  }
  else{
    mapV[key] += 1;
  }
}

template <class T>
void Counter<T>::Increment(const T & key, int n) const{
  if(mapV.find(key) != mapV.end()){
    typename std::map<T, int>::iterator it;
    for(it = mapV.begin(); it != mapV.end(); it++){
      if(it->first==key){
        it->second = it->second+n;
      }
    }
  }
  else{
    mapV[key] += n;
  }
}

template <class T>
void Counter<T>::Decrement(const T & key) const{
  if(mapV.find(key) != mapV.end()){
    typename std::map<T, int>::iterator it;
    for(it = mapV.begin(); it != mapV.end(); it++){
      if(it->first==key){
        if(it->second > 1){
          it->second = it->second-1;
        }
        else{
          Remove(key);
        }
      }
    }
  }
}

template <class T>
void Counter<T>::Decrement(const T & key, int n) const{
  if(mapV.find(key) != mapV.end()){
    typename std::map<T, int>::iterator it;
    for(it = mapV.begin(); it != mapV.end(); it++){
      if(it->first==key){
        if(it->second - n > 0){
          it->second = it->second-n;
        }
        else{
          Remove(key);
        }
      }
    }
  }
}

template <class T>
T Counter<T>::MostCommon()const{ //FATAL ERROR
  return this->MostCommon(1)[0];
}


template <class T>
std::vector<T> Counter<T>::MostCommon(const int & n) const{//FATAL ERROR//FATAL ERROR
  std::vector<std::pair<T,int>> vec;

  typename std::map<T,int> :: iterator it;
  for(it = mapV.begin(); it != mapV.end(); it++){
    vec.push_back(std::make_pair(it->first,it->second));
  }
  std::sort(vec.begin(),vec.end(), sortByCount);

  std::vector<T> most;
  for(int i = 0; i<n && i < vec.size(); i++){
    most.push_back(vec[i].first);
  }
  return most;
}


template <class T>
T Counter<T>::LeastCommon() const{//FATAL ERROR
  return this->LeastCommon(1)[0];
}
template <class T>

std::vector<T> Counter<T>::LeastCommon(int n) const{//FATAL ERROR
  std::vector<std::pair<T,int>> vec;

  typename std::map<T,int> :: iterator it;
  for(it = mapV.begin(); it != mapV.end(); it++){
    vec.push_back(std::make_pair(it->first,it->second));
  }
  std::sort(vec.begin(),vec.end(), sortByCount);

  std::vector<T> most;
  for(int i = 0; i<n && i < vec.size(); i++){
    most.push_back(vec[i].first);
  }
  return most;
}

template <class T>
std::map<T,double> Counter<T>::Normalized()const{
  std::map<T,double> sol;
  std::pair<T,double> temp;
  int total_count = Count();
  for(std::pair<T, int> pair : mapV){
      temp.first = pair.first;
      temp.second = (double)pair.second/(double)total_count;
      sol.insert(temp);
  }
  return sol;
}

template <class T>
std::set<T> Counter<T>::Keys()const{
  std::set<T> sol;
  for(std::pair<T, int> pair : mapV){
    sol.insert(pair.first);
  }
  return sol;
}

template <class T>
std::vector<int> Counter<T>::Values()const{
  std::vector<int> sol;
  for(std::pair<T, int> pair : mapV){
    sol.push_back(pair.second);
  }
  return sol;
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const Counter<U> &b){
  os <<"{";
  for (std::pair<U, int> elem : b.mapV){
    os <<elem.first<< ":" <<elem.second<<",";
  }
  os <<"}"<< std::endl;
  return os;
}
