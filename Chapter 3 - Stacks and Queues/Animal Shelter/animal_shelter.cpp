//https://ide.geeksforgeeks.org/eP2uF9CQ7J
#include <bits/stdc++.h>
using namespace std;

struct Animal{
    int arrivalTime;
    bool check;
};

class AnimalQueue{
    protected:
    queue<Animal> dogs;
    queue<Animal> cats;
    int order = 0;
    public:
    Animal getOut(string c){
        Animal res;
        if(c == "dog"){
            res = dogs.front();
            dogs.pop();
        }
        else{
            res = cats.front();
            cats.pop();
        }
        return res;
    }
    void enqueue(Animal A){
        if(A.check){
            dogs.push(A);
            order++;
        }
        else{
            cats.push(A);
            order++;
        }
    }

    Animal dequeueDog(){
        return getOut("dog");
    }

    Animal dequeueCat(){
        return getOut("cat");
    }

    Animal dequeueAny(){
        if(dogs.empty())
            return getOut("cat");
        else if(cats.empty())
            return getOut("dog");
        else{
            if(dogs.front().arrivalTime < cats.front().arrivalTime){
                return getOut("dog");
            }
            else
                return getOut("cat");
        }
    }
};


int main(){
    Animal dog, cat;
    dog.check = true;
    cat.check = false;
    AnimalQueue aq;
    aq.enqueue(dog);
    aq.enqueue(cat);
    aq.enqueue(dog); 
    aq.enqueue(cat);
    Animal x = aq.dequeueAny();
    if(x.check) cout<<"Dog dequeued\n";
    else cout<<"Cat dequeued\n";
    Animal y = aq.dequeueDog();
    if(y.check)cout<<"Dog dequeued\n";
    Animal z = aq.dequeueCat();
    if(!z.check)cout<<"Cat dequeued\n";
}