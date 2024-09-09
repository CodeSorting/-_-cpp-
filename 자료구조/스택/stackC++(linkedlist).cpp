/*
?��?���? ?��?�� 쪽에?���? ?��?�� ?��?�� ?��?��?�� ?��루어�?�?�? ?���? 리스?���? 구현?��?�� ?��?��?��. ?���? 리스?���? 구현?��?�� push,pop, top ?��?��?�� 모두 O(1)?���?.
?���? 리스?���? 구현?�� 경우 head ?��?��?���? top ?��?���? 바로 �?리키�? ?��?�� ?��?���? ?���?, push�? ?�� ?��마다 head�? �?리키?�� ?��로운 ?��?���? 만들?�� 그걸 ?��?�� head�? ?��?��?��?���?, pop?�� ?�� ?��마다 head ?��?���? �??���? �? ?��?�� ?��?���? head�? 바꾸?�� ?��?���? 구현?�� ?�� ?��?��?��?��.
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class UnderflowException{};

template<typename T>
class ListNode{ //리스?�� ?��?�� ?��?��?��
public:
  T value; //�?
  ListNode<T> *next; //?��?��?��?��

  ListNode<T>(): next(nullptr){}
  ListNode<T>(T value1,ListNode<T> *next1): value(value1), next(next1){}
};

template<typename T>
class Stack{ //?��?�� ?��?��?��
public:
  int size; //?��?��?���?
  ListNode<T> *tail; //?��?�� 값을 �?리킴.

  //?��?��?��
  Stack<T>(): size(0), tail(nullptr){}

  //?��멸자
  ~Stack<T>(){
    ListNode<T> *t1 = tail, *t2;
    while (t1 != nullptr){
      t2 = t1->next; //?��?��?��?���?->멤버�??��?���? = �?
      delete t1;
      t1 = t2;
    }
  }

  //멤버 ?��?��
  void push(T value){
    tail = new ListNode<T>(value, tail); //tail�? ?�� listnode�? ?��결한?��.
    size++;
  }

  T top(){ //�? ?�� ?��?�� 반환
    try{
      //?��?��처리 : ?��?��?�� 비어?��?��
      if (size==0) throw UnderflowException();

      return tail->value;
    }
    catch(UnderflowException e){
      cerr<<"?��?��?�� 비어 ?��?��?�� top ?��?��?�� ?��?��?��?��?��?��."<< endl;
      exit(1);
    }
  }

  void pop(){ //�? ?��?�� ?��?�� ?���?
    try{
      //?��?�� 처리: ?��?��?�� 비어 ?��?��
      if (size==0) throw UnderflowException();

      ListNode<T> *temp = tail->next;
      delete tail;
      tail = temp;
      size--;
    }
    catch(UnderflowException e){
      cerr<<"?��?��?�� 비어 ?��?��?�� pop ?��?��?�� ?��?��?��?��?��?��." << endl;
      exit(2);
    }
  }
};

template<typename T>
ostream& operator <<(ostream &out,const Stack<T> &LL){//?��?��?��?�� ?�� 줄에 차�?????�? 출력
  ListNode<T> *temp = LL.tail;
  out<<"top [";
  for (int i=0;i<LL.size;i++){
    out<<temp->value;
    temp = temp->next;
    if (i < LL.size-1) out<<", ";
  }
  out<<"] bottom";
  return out;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Stack<int> S;
  S.push(0); cout << S << endl;
  S.push(1); cout << S << endl;
  S.push(2); cout << S << endl;
  S.push(3); cout << S << endl;
  S.pop(); cout << S << endl;
  S.push(4); cout << S << endl;
  S.pop(); cout << S << endl;
  S.pop(); cout << S << endl;
  S.push(5); cout << S << endl;
  S.pop(); cout << S << endl;
  S.pop(); cout << S << endl;
  S.pop(); cout << S << endl;
}