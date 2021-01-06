#define CATCH_CONFIG_MAIN
#include <vector>
#include <map>
#include "iostream"

template <class T>
class Counter{
  std::vector<int> values;
public:
  Counter(); // done
  Counter(std::vector<T> vals); // done
  int Count(); //TOTAL COUNTS // done
  //int Count(T key); // ACCESS THE COUNT
  int Count(T min, T max); // THIS GIVES THE RANGE  done
  void Remove(T key); //done
  void Increment(T key); // done
  void Increment(T key, int n); // done
  void Decrement(T key); // done
  void Decrement(T key, int n); // done
  //T MostCommon();
  std::vector<T> MostCommon(int n);
  //T LeastCommon();
  std::vector<T> LeastCommon(int n);
  std::map<T, double> Normalized();
  std::ostream& operator<<(std::ostream& os, const Counter<U> &b);

private:
  //counts the occurrences of hashable objects
  std::map<T,int> *map_;

};
    template <class T>
    Counter<T>::Counter() {
      std::map<T,int> *temp = new std::map<T,int>;
      map_ = temp;
    }

    template <class T>
    Counter<T>::Counter(std::vector<T> vals) {
      values = vals;

    }
    template <class T>
    int Counter<T>::Count() {
      int count = 0;
      std::vector <int> key;

      for(auto i = map_->begin(); i != map_->end(); i++ ) {

        key.push_back(i->second);
      }
      for(int i=0 ; i< key.size(); i++)
      {
        count += key[i];
      }

      return count;
    }

    template <class T>
    int Count(T min, T max) {
      std::vector <int> index;
      std::vector <T> key;
      int count = 0;
      for(auto i =map_->begin(); i != map_->end(); i++)
      {
        key.push_back(i->first);
        index.push_back(i->second);
      }
      for(int i=0 ; i<index.size(); i++)
      {
        if ((key[i] - min) <= (max-min))
        {
        count += index[i];
        }
      }

      return count;
    }

    template <class T>
    void Counter<T>::Remove(T key) {
      typename std::map<T, int>::iterator i = map_->find(key);
        if(map_->count(key) > 0)
        {
          map_->erase(i);
        }
        else if (map_->count(key) == 0)
        {
          std::cout<<"Does not exist"<<std::endl;
        }

    }

    template <class T>
    void Counter<T>::Increment(T key) {
    typename std::map<T, int>::iterator i = map_->find(key);
      if(i != map_->end())
      {
        i->second++;
      }
    }
    template <class T>
    void Counter<T>::Increment(T key, int n) {
    typename std::map<T, int>::iterator i = map_->find(key);
      if(i != map_->end())
      {
        i->second+=n;
      }
    }
    template <class T>
    void Counter<T>::Decrement(T key) {
    typename std::map<T, int>::iterator i = map_->find(key);
      if(i != map_->end())
      {
        i->second--;
      }
    }

    template <class T>
    void Counter<T>::Decrement(T key, int n) {
    typename std::map<T, int>::iterator i = map_->find(key);
      if(i != map_->end())
      {
        i->second-=n;
      }
    }
    // std::vector<T> MostCommon(int n);
    // std::vector<T> LeastCommon(int n);
    // std::map<T, double> Normalized();
    std::ostream& operator<<(std::ostream& os, const Counter<U> &b){
      for(auto i= b.map_->begin();i++)
      {
        os<<"Key: "<<i->first<<" Value: "<<i->second<<std::endl;
      }
      return os;
    }
