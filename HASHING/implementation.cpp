#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

template<typename V>
// this is how we work on separate chaining 
// basically every node in map contains head of a linked list 
class MapNode{
    public:
    string key;
    V value ;
    MapNode* next;
    MapNode(string key , V value){
        this->key = key ;
        this->value = value ;
        next = NULL;
    }
    // to delete the linked list 
    ~MapNode(){
        delete next;
    }
};
template<typename V>
class ourmap{
    //? i din't get ** wali baat 
    MapNode<V>**buckets;
    int size ;
    // number of buckets to stores heads of linked lists 
    int numBuckets;

    Public:
    ourmap(){
        size = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];
        for(int i = 0 ; i < numBuckets ;i++){
            buckets[i] = NULL;
        }
    }
    ~ourmap(){
        // delete every linked list
        for(int i = 0 ; i < numBuckets ; i++){
            delete buckets[i];
        }
        delete []buckets;
    }
    int size(){
        return count ;
    }
    V getvalue (string key){

    }
    private:
    int getBucketindex(string key){
         int hashcode ;;
         //key ke corresponding p base pe value 
         //hashcode
         // abc = a*(p*P)+b*(p)+c*(p^0)
         int currentcoeff =1;
         for(int i = key.length()-1 ; i>=0 ;i--){
            hashcode += key[i]*currentcoeff;
            hashcode = hashcode%numBuckets;
            // p as  a prime number 
            // 37 can be any other prime number also 
            currentcoeff*= 37 ;
            currentcoeff = currentcoeff%numBuckets;
         }
         return hashcode%numBuckets;
    }

    public:
    void insert(string key , V value ){
        int bucketIndex = getBucketindex(string key);
        MapNode<V>*head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key==key){
              head->value = value ;
              return ;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        // jab nyi node create krke data liya to count++
        MapNode <V>*node = new MapNode<V>(key , value );
        node->next = head;
        buckets[bucketIndex]= node;
        // count for all enteries
        count++;
    }
    V remove(string key){

    }
};





int main(){

}