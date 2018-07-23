// libraries are difficult to learn in C++
// STL - standard library
// deligation of the smaller tasks to the library
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <deque>
#include <array>
#include <iostream>
#include <map>
#include <random>

#include "Resource.h"
#include "Employee.h"
#include "Print.h"
#include "Lambda.h"

using std::cout;
using std::endl;
using std::vector;
using std::array;
using std::deque;
using std::map;
using std::pair;
using std::string;
using std::swap; // moved to STL at some point

using std::random_device;
using std::mt19937;

using std::find;

void counting();
void finding();
void sorting();
void comparing_accumulating();
void power_of_iterator();
void useful_operation();
void manipulating_collections();

// Collections
// Algorithms
// Iterators

// Algorithms:
// - work on any container
// - no matter what it contains
// - work on ranges
// - typically work through iterators
// - iterators provide functionality
// - include <algorithm>

// Headers:
// <algorithm>
//
// Collections:
// <vector>, <array>, <list>, <stack>, ...

int main(){

    // don't write the raw loop!
    // use STL: the standard algorithms
    // no comments needed since functions speak for themselves, e.g.,
    // count, count_if
    // find, find_of
    // copy, copy_if

    // counting();
    // finding();
    // sorting();
    // comparing();
    // comparing_accumulating();
    // manipulating_collections();
    // power_of_iterator();
    useful_operation();

    // naming conventions
    // -----------------------------------------------------------------
    // - two iterators;
    // - iterator and a number, e.g., copy_n(), fill_n(), generate_n()
    // - three iterators

    // rotate(); // first, newfirst, last
    // rotate_copy() // first, newfirst, last, destfirst
    // nth_element(first, nth, last);

    // if we have integer value it is eaither
    // _n : the first n parameter that function is dealing with
    // target value, we are looking for, find(.., .., 3)
    // starting value, iota(...., 1)

    // _if
  
    // _n

    // is_
  
    // stable_

    return 0;
}

void useful_operation(){
    // partial_sort_copy = top n entries in the collection
    //
    // swap()
    //
    // iter_swap()
    // swap_ranges()
    //

    int a{4}, b{5};
    swap(a, b);

    vector<int> evens {2, 4, 6, 8, 10};
    vector<int> odds {1, 3, 5, 7, 9};

    auto v1 = evens;
    swap(v1[0], v1[1]); // first ways to do the standart swap
    cout << "swap:"; printVector(v1);
    iter_swap(begin(v1), begin(v1)+1); // or to swap the begin iterator with the next element
    cout << "iter_swap:"; printVector(v1);
    cout << endl;

    auto v2 = odds;
    swap(v1[0], v2[0]);
    cout << "v1:"; printVector(v1);
    cout << "v2:"; printVector(v2);
    cout << endl;

    iter_swap(begin(v1), find(begin(v2), end(v2), 5));
    cout << "v1:"; printVector(v1);
    cout << "v2:"; printVector(v2);
    cout << endl;

    v1 = evens;
    v2 = odds;


    swap_ranges(begin(v1), find(begin(v1), end(v1), 6), begin(v2));
    cout << "v1:"; printVector(v1);
    cout << "v2:"; printVector(v2);
    cout << endl;
    // rotating in a certain range

    vector<int> tasks(6);
    iota(begin(tasks), end(tasks), 1);

    auto two = find(begin(tasks), end(tasks), 2);
    auto four = find(begin(tasks), end(tasks), 4);
    printVector(tasks);
    rotate(two, four, four + 1); // first, middle, last
    // which element should be at the start of the range 
    // when the rotation is complete
    //
    printVector(tasks);

    // partition of the collection
    // partition
    // stable_partition

    // marking the element -> they will be on the top
    // the rest

    // drag and drop
    // first we write the partitionof selected and non-selected elements
    // and them we move them or do smth with them

    vector<int> numbers(8);
    iota(begin(numbers), end(numbers), 1);
    cout << "numbers: "; printVector(numbers);

    auto selected = stable_partition(begin(numbers), end(numbers), [](int i) {return i % 2 == 0;});
    cout << "selected (first add, then even): "; printVector(numbers);
    
    auto search_result = find(begin(numbers), end(numbers), 4);
    cout << "elemnt: " << *search_result << endl;
    //rotate(begin(numbers), selected, search_result); // rotation till four
    //cout << "rotate: "; printVector(numbers);
}

void manipulating_collections(){
    // managing the collection

    // copying
    // operation=
    // copy()
    // copy_if()
    // copy_n() - copy n elements
    // copy_backward

    vector<int> source {3, 6, 1, 0, -2, 5};

    // copying the whole vector by providying the range
    vector<int> v2(source.size());
    copy(begin(source), end(source), begin(v2));

    // copying with =operator for the entire collection
    auto v3 = source;

    //------------------------------------------------------------------------
    // copying
    //------------------------------------------------------------------------
    // copying to a position of a certain element
    auto position = find(begin(source), end(source), 1);
    vector<int> v4(source.size());
    // new range [(begin(source), position]
    copy(begin(source), position, begin(v4));

    // copying those elements who safisfy the condition
    vector<int> v5(source.size());
    copy_if(begin(source), end(source), begin(v5),
        [](int elem){ return elem % 2 == 0;} // the condition the int should satify
    );
    // copying number of element
    copy_n(begin(v5), 3, begin(v2));

    // copying inside the source vector (within the same collection)
    // safe
    copy(begin(source), position + 1, position + 1);


    // doesn't sqitch the 
    cout << "before copying backwords " << endl;
    printVector(v3);    
    printVector(source);    
    copy_backward(begin(v3), end(v3), end(source));
    cout << "after copying backwords " << endl;
    printVector(v3);    
    printVector(source);    
    cout << endl;
    // if we want to shift the same collection within itsel
    // 3, 6, 1, 0, -2, 5 ->
    // 3, 3, 6, 1, 0, -2, 5
    copy_backward(begin(source), end(source) - 1, end(source));

    //------------------------------------------------------------------------
    // non-copyable collections
    //------------------------------------------------------------------------
    //move()
    //mode_backward()

    //------------------------------------------------------------------------
    // removeling elemnts from collections
    //------------------------------------------------------------------------
    // 
    // important!
    // remove returns new end
    // we have to take care of the tail ourselves

    // removing elements from the collection
    auto newend = remove(begin(source), end(source), 3);
    int s = source.size();
    int logicalsize = newend - begin(source);

    // erase (removes the tail of the useless elements)
    // erase should be done in the end after all the operations are over
    source.erase(newend, end(source));

    source = v3;
    source.erase(remove(begin(source), end(source), 3), end(source));

    // -----------------------------------------------------------------------
    // example from Cppreference

    std::vector<int> c = {1, 2, 3, 4, 5, 6, 7};
    int x = 5;
    std::cout << "c: ";
    std::for_each(c.begin(), c.end(), [](int i){ std::cout << i << ' '; });
    std::cout << endl;
 
    // erase 
    // funciton removes either a single element (position) or a range of elements ([first,last)).
    // erase the 6th element
    c.erase (c.begin()+5);

    // erase the first 3 elements
    c.erase (c.begin(),c.begin()+3);

    // return new end of c
    auto c_newend = std::remove_if(c.begin(), c.end(), [x](int n) { return n < x; });
    // new array is c with correct value [c.begin(), c_newend] =>
    // therefore the value that from the old c must be removed 
    c.erase(c_newend, c.end());
 
    std::cout << "c: ";
    std::for_each(c.begin(), c.end(), [](int i){ std::cout << i << ' '; });
    std::cout << endl;
 
    // the type of a closure cannot be named, but can be inferred with auto
    // since C++14, lambda could own default arguments
    auto func1 = [](int i = 6) { return i + 4; };
    std::cout << "func1: " << func1() << endl;
 
    // like all callable objects, closures can be captured in std::function
    std::function<int(int)> func2 = [](int i = 6) { return i + 4; };
    std::cout << "func2: " << func2(6) << endl;
    // -----------------------------------------------------------------------

    vector<Resource> vr(5);

    vr[0].setValue(8);
    vr[1].setValue(9);
    vr[2].setValue(10);
    vr[3].setValue(8);


    vr[4].setValue(7);

    cout << "object count = " << Resource::getCount() << endl;
    cout << "original vector of recourses: ";
    printVector(vr);
    auto newend2 = remove_if(begin(vr), end(vr), [](Resource& r){return r.getValue() == 8; });
    // things are not removed but just copied
    cout << "vector of recourses after removing all 8 (no erasing): ";
    printVector(vr);
    // this shows that even though 8 was removed, elements were shifted,
    // we still have the old numbers at the end to be erased
    vr.erase(newend2, end(vr));
    cout << "vector of recourses after removing all 8 (with erasing): ";
    printVector(vr);
    cout << endl;

    // -----------------------------------------------------------------------
    // creating and filling the collections
    // -----------------------------------------------------------------------

    //
    // - collection are default intialized
    // - fill(), -fill_n()
    // generate(), generate_n()
    //

    vector<int> v6(10);

    int value_tofill = 1;
    fill(begin(v6), end(v6), value_tofill);
    printVector(v6);

    // fill 6 element with 2
    int num_vals = 6;
    value_tofill = 2;
    fill_n(begin(v6), num_vals, value_tofill);
    printVector(v6);

    // iota() - greak letter, is 1, 2, 3, 4 ... 10
    int init_value = 1;
    iota(begin(v6), end(v6), 1);
    printVector(v6);

    int index = 10;
    // we capture index by reference, fillin the elemnt of the v6 and decreminate index
    generate(begin(v6), end(v6), [&index](){ return --index;});
    printVector(v6);

    source = v6;
    index = 1;
    // into the v6 we put element index*2, (index+1)*2
    int factor = 2;
    num_vals = 7;
    generate_n(begin(v6), num_vals, [&index, factor](){ return (index *= factor); });
    printVector(v6);
    cout << endl;

    // -----------------------------------------------------------------------
    // replacing value
    // -----------------------------------------------------------------------

    // replaceing the value
    // replace()
    // replace_if

    // replace every 2 by 7
    int old_elem = 2;
    int new_elem = 7;
    replace(begin(v6), end(v6), old_elem, new_elem);
    printVector(v6);

    // replace according to condition
    auto condition = [](int elem) {return elem < 16;};
    replace_if(begin(v6), end(v6), condition, new_elem);
    printVector(v6);
    cout << endl;

    // -----------------------------------------------------------------------
    // transforming
    // -----------------------------------------------------------------------

    // transforming the elements of the entire collection
    // do smth to the element
    // put the result of the operation into the collection
    // working pair wise with  elements

    // we are doing the tranformation in place
    cout << "initial vector: "; printVector(source);
    transform(begin(source), end(source), begin(source), [](int elem) {return elem * 2;});
    cout << "doubled vector: "; printVector(source);

    // pair wise operation:
    // range of the 1st with the begining and end,
    // range of the 2nd wiht the begining
    // destination
    // lambda
    transform(begin(source), end(source) - 1, begin(source) + 1, begin(v6), [](int elem1, int elem2){return elem1 + elem2;});
    cout << "destination of pair-wise +: "; printVector(v6);

    transform(begin(source), end(source) - 1, begin(source) + 1, begin(v6), [](int elem1, int elem2){return elem1 - elem2;});
    cout << "destination of pair-wise -: "; printVector(v6);

    // 1 is the initial value
    iota(begin(v6), end(v6), 1);
    cout << "iota 1: "; printVector(v6);
    iota(begin(source), end(source), 2);
    cout << "iota 2: "; printVector(source);

    vector<int> v7(10);
    transform(begin(v6), end(v6), begin(source), begin(v7), [](int elem1, int elem2){return elem1 + elem2;});
    cout << "iota 1 + iota 2: ";
    printVector(v7);


    // -----------------------------------------------------------------------
    // eliminating the duplicates
    // -----------------------------------------------------------------------

    // sort()
    // adjacent_find()
    // remove()

    // sort()
    // unique(), unique_sort()

    // unique() = sort() + consequitive_find()
    cout << "before removing duplicates: ";printVector(v2);
    auto new_end = unique(begin(v2), end(v2));
    cout << "after removing duplicates: ";printVector(v2);

    v2[3] = -2;
    auto v8 = v2; // we need the copy with the duplicates
    v2.erase(new_end, end(v2));
    cout << "after removing duplicates (with erase): ";printVector(v2);

    unique_copy(begin(v8), end(v8), begin(v7));
    cout << "unique elements: "; printVector(v7);

    // -----------------------------------------------------------------------
    // reversing and swapping
    // -----------------------------------------------------------------------
    // iter_swap()
    // reverse()
    // reserve_copy()

    string sentence = "Hello world!";
    reverse(begin(sentence), end(sentence));
    cout << "new sentence: " << sentence << endl;

    printVector(v7);
    iter_swap(begin(v7), end(v7)-1); //swap the first and the last elements
    printVector(v7);

    string orig = "|             |";
    reverse_copy(begin(sentence), end(sentence), begin(orig));
    cout << orig << endl;
}

void power_of_iterator(){
    
    // ------------------------------------------------------------------------
    // back_inserter && front_inserter
    // ------------------------------------------------------------------------
    
    // inserting can be reacher
    vector<int> v1(10);
    fill(begin(v1), end(v1), 1);
    fill_n(begin(v1), 6, 2);
    iota(begin(v1), end(v1), 1);

    // no idea how big the vector should be
    // no default contructor
    // what if the default contructor is expensive

    // different iterator -> 'inserting iterator'
    // back_inserter
    // front_inserter

    vector<int> v2; // we dont know the size
    fill_n(back_inserter(v2), 6, 2);
    cout << "back_inserter: "; printVector(v2);

    // n = 0 - alias capture (this way we don't have the loose n variable)
    // mutable means that n can be changed by the lambda function
    // adding to the q3
    generate_n(back_inserter(v2), 10, [n = 0]() mutable {return n++;});
    cout << "back_inserter: "; printVector(v2);

    deque<int> q3;
    fill_n(front_inserter(q3), 6, 2);
    cout << "fill_n, front_inserter on the queue: ";printVector(q3);
    // adding to the q3
    generate_n(front_inserter(q3), 10, [n = 0]() mutable {return n++;});
    cout << "generate_n, front_inserter on the queue: ";printVector(q3);

    // changing the value with the iterator
    // begin(v): [1, 2, 3] -> [9, 2, 3] -> [9, 6, 3]

    // front_inserter(v): [1, 2, 3] -> [9, 1, 2, 3] -> [6,9, 1, 2, 3]

    v2.clear();
    cout << "v1: ";printVector(v1);
    transform(begin(v1), end(v1), back_inserter(v2), 
        [](int elem) {return elem * 2;});
    cout << "v2: ";printVector(v2);

    vector<int> v3 {3, 6, 1, 0, -2, 5};
    vector<int> v5;

    // copy only odd elements
    copy_if(begin(v3), end(v3), back_inserter(v5), [](int elem) {return elem % 2 == 0;});
    printVector(v5);

    // copy only unique elements from {3, 6, 1, -2, -2, 5}
    v3[3] = -2;
    vector<int> v6;
    unique_copy(begin(v3), end(v3), back_inserter(v6)); // makes a copy of only unique elements,
    // one of the -2 is not copied
    printVector(v6);

    // ------------------------------------------------------------------------
    // reverse iterator
    // ------------------------------------------------------------------------
    
    // rfront
    // rback

    // end - points to the end where there is no element
    // [1, 2, 3] x
    // rend - point to the element just before the begining
    // x [1, 2, 3]
    // begin - points to the first element of the collection
    // [x, 2, 3]
    // rbegin - points to the last elemnt in the collection
    // [1, 2, x]

    // ++ on the backward iterator, goes <=

    // iterator arithmetic
    // auto ! - you  don't want to tyoe the type
    // ++ - next, -- next backwords
    // (iter1 - iter2) - to get the distance between iterators

    // allows to get the index in the vector!

    string sentence = "hello world!";
    string reverse;
    reverse_copy(begin(sentence), end(sentence), back_inserter(reverse));
    cout << "reversed: " << reverse << endl;

    v2.clear();
    cout << "original: "; printVector(v1);
    copy(rbegin(v1), rend(v1), back_inserter(v2));
    cout << "reversed: "; printVector(v2);

    v1[5] = 2;

    // vector iterator on the vector of integers
    auto two = find(begin(v1), end(v1), 2);
    auto twoIndx = two.base();
    auto distance = two - begin(v1);
    two++;

    // reverse vector iterator on the vector of integers
    auto rtwo = find(rbegin(v1), rend(v1), 2);
    distance = rtwo - rbegin(v1);
    rtwo++;

    auto three = find(begin(v1), end(v1), 3);
    bool firsthalf = (three - begin(v1) < end(v1) - three);
    // compare the three pointer to the begining and
    // theree pointer to the end
    auto nine = find(begin(v1), end(v1), 9);
    firsthalf = (nine - begin(v1) < end(v1) - nine);


    // const interators
    // cbegin() returns const_iterator
    //
    // cend()
    // the changes in the iterators

    array<const int, 5> ca = { 3, 1, 6, 0, 2 };
    auto it = begin(ca);
    it++;
    int i = *it;

    //vector<const int> vc;

    it = std::find(begin(ca), end(ca), 1);
    it++;

    auto it2 = begin(v2);
    it2++;
    *it2 = 7;

    auto cit = cbegin(v2);
    cit++;


}
void comparing_accumulating(){
    // comparing and accumulating
    // ----------------------------------------------------
    // equal()
    // std::pair - any combination of the type, but it is strongly typed
    // std::map contains pairs
    // .first and .second
    
    // comparing
    vector<int> a{1, 2, 3, 4, 5};
    vector<int> b{1, 2, 0, 5};

    bool same = (a.size() == b.size()); // if they are not the same size -  they are definitely not the same
    same = equal(begin(a), end(a), begin(b), end(b));

    // we can get the interator to the point where the mismatch happened
    auto firstchange = mismatch(begin(a), end(a), begin(b)); // pair of iterators, so we need to dereference them
    int avalue = *(firstchange.first);
    int bvalue = *(firstchange.second);

    // how long were they the same (pointer arithmetics)
    auto distance = firstchange.first - begin(a);
    cout << "the mismatch happened on the position " << distance << endl;

    // adding up -> accumulate()
    int total = 0;
    total = accumulate(begin(a), end(a), total); // zero here is the starting value
    total = accumulate(begin(a), end(a), 0, // initial value of total = 0
                        [](int total, int i){
                            // total is the partial result that being accumulated
                            // i is the i-th value of the collection
                            cout << "total = " << total << " >> adding i = " << i << "\n";
                            if (i % 2 == 0) return total + i;
                            return total;
                        }
    );
    cout << endl;

    // accumulate is special case of how lambda are used
    // summation can be re-written as

    total = 0;
    std::for_each(begin(a), end(a), [&total](int i){
                           // total is the partial result that being accumulated
                           // i is the i-th value of the collection
                           cout << "total = " << total << " >> adding i = " << i << "\n";
                           if (i % 2 == 0)
                               total = total + i;
                       }
    );
    cout << endl;


    total = accumulate(begin(a), end(a), 1, // total = 1, have to start with 1 because of the multiplication
                       [](int total, int i){
                           // total is the partial result that beeing accumulated
                           // i is the i-th value of the collection
                           cout << "total = " << total << " >> mult by i = " << i << "\n";
                           return total * i;
                       }
    );
    cout << endl;

    vector<string> words{"one", "two", "three"};

    auto allwords = accumulate(begin(words), end(words), string{});
    int length = allwords.size();

    // string{"Words: "} is the initial string
    allwords = accumulate(begin(words), end(words), string{"Words: "},
        [](const string& total, const string& word){
            cout << "total = " << total << " >> adding word " << word << "\n";
            return total + word + ", "; }
    );
    length = allwords.size();
    cout << allwords <<  endl;


    string s = accumulate(begin(a), end(a), string{"The numbers are:"},
        [](const string& total, const int i){
            cout << "total = " << total << " >> adding a number " << std::to_string(i) << "\n";
            return total + std::to_string(i) + ", ";}
    );
    cout << s << endl;
    b = a;

    // for_each() // ranged for
    // ---------------------------
    // we can pass anything we want
    // works for any ranges
    for_each(begin(b), end(b), [](int& elem){elem = 2;});

    for_each(begin(b), end(b), [](int& elem){cout << elem << "\n";});

    auto first_three = find(begin(b), end(b), 3);
    for_each(first_three, end(b), [](int& elem){ elem = 0; });
}

void sorting(){

    // sort(it1, it2, lambda)
    vector <int> v{ 4, 1, 0, 1, -2, 3, 7, -6, 2, 0, 0, -9, 9 };
    auto v2 = v;    // copy will be sorted

    cout << "original vector: " << endl;
    printVector(v);
    
    sort(begin(v2), end(v2)); // default will be elem1 < elem2
    cout << "accent sort: " << endl;
    printVector(v2);
    
    sort(begin(v2), end(v2), [](int elem1, int elem2){return elem1 > elem2;}); // descended sort
    cout << "descend sort: " << endl;
    printVector(v2);

    sort(begin(v2), end(v2), [](int elem1, int elem2){return abs(elem1) > abs(elem2);});
    cout <<  "descend sort (by the absolute value):" << endl;
    printVector(v2);

    // stable sort
    std::vector<Employee> staff{
        {"Kate", "Gregory", 1000},
        {"Obvious", "Artificial", 456},
        {"Fake", "Name", 1100},
        {"Alan", "Turing", 2004},
        {"Grace", "Hopper", 20550},
        {"Anita", "Borg", 200000}};

    cout << "\noriginal list of the Emplyees:" << endl;
    printVector(staff);

    // sort staff w.r.t. the salary
    sort(begin(staff), end(staff), [](Employee em1, Employee em2){return em1.getSalary() < em2.getSalary();});
    cout << "\nsorted by the salary list of the Emplyees:" << endl;
    printVector(staff); 
    
    sort(begin(staff), end(staff), [](Employee em1, Employee em2){return em1.getSortingName() < em2.getSortingName();});
    cout << "\nsorted by the name list of the Emplyees:" << endl; 
    printVector(staff);

   // stable sort will keep the staff softer with their Sorting Name after sorting then w.r.t. the salary
    stable_sort(begin(staff), end(staff), [](Employee em1, Employee em2){return em1.getSalary() < em2.getSalary();});
    cout << "\nstable sorted by the name list of the Emplyees:" << endl; 
    printVector(staff);


    // is sorted ?
    auto sorted = is_sorted(begin(v2), end(v2)); // it will give false since it is not sorted
    cout << "\nis v2 sorted:" << sorted << endl; 
    sorted = is_sorted(begin(v2), end(v2), [](int elem1, int elem2){return abs(elem1) > abs(elem2);});
    cout << "\nis v2 sorted (according to the descend rule):" << sorted << endl; // yes because it was the last opration

    // find the largest
    // find the smallest
    // is sorted is playing a huge role in finding limit values
    // upper_bound() finds the first element that is larger then the target
    // lower_bound() finds the first element that is smaller then the target

    // two ways to the max elememt
    // fastest sort 0(nlog(n)
    int high = *(max_element(begin(v), end(v))); // O(n)
    int low  = *(min_element(begin(v), end(v))); // O(n)
    cout << "max = " << high << ", min = " << low << endl;

    sort(begin(v2), end(v2));
    low = *(begin(v2));
    high = *(end(v2) - 1);
    cout << "max = " << high << ", min = " << low << endl;
    
    // in a sorted collection
    int positive = *(upper_bound(begin(v2), end(v2), 0)); // on a sorted be can
    cout << "first name that greated then 0 = " << positive << endl;
    

    sort(begin(staff), end(staff), [](Employee em1, Employee em2){return em1.getSortingName() < em2.getSortingName();});
    auto p = lower_bound(begin(staff), end(staff), "Gregory, Kate", [](Employee e1, string n){return e1.getSortingName() < n;});
    int sal = p->getSalary();
    cout << "salary of the emp before Gregory, Kate = " << positive << endl;
    
    // shuffle
    random_device randomDevice;
    mt19937 generator(randomDevice());

    shuffle(begin(v2), end(v2), generator);

    // for very large collections
    // the result of partial sort of 4 element out of 100 are such that the first places there are 4 smallest elements
    // this is useful if we need to do sorting
    // on the smaller parts of the huge collection
    // we do the sorting whenever it is needed

    // {1, 5, 4, 3, 9, 7}
    // sort such that: 
    // - before 4 are smaller elements 
    // - after 4 bigger elements
    // {1, 3, 4, 5, 9, 7}

    // middle - indicated where the vector won't be sorted from
    cout << "original vector" << endl;
    printVector(v2);
    // the index of 4 will be the point in the array till which the vector won't be sorted 
    partial_sort(begin(v2), find(begin(v2), end(v2), 4), end(v2));
    cout << "partial sort w.r.t 4 = " << endl;
    printVector(v2);

    // get top 3 Sales people

    // show until the collection is sorted
    int breakpoint = *(is_sorted_until(begin(v2), end(v2)));

    vector<int> v3(3);
    // makes a copy of the sorted elements
    // we want a top 3 sales or important values
    partial_sort_copy(begin(v), end(v), begin(v3), end(v3)); // not stable
    cout << "copy of 3 sorted elements = " << endl;
    printVector(v3);
    
    // groups
    // we pick a place, e.g., a middle
    // we have first element less then average
    // and we have second half with larger elements
    v2 = {1, 5, 4, 2, 9, 7, 3, 8, 2};
    int i = *(begin(v2) + 4);
    nth_element(begin(v2), end(v2) + 4, end(v2));
    i = *(begin(v2) + 4);

}

void finding(){

    std::vector<int> v{2, 4, 6, 6, 1, 3, -2, 0, 11, 2, 3, 2, 4, 4, 2, 4};
    string s{"Hello I am a sentence!"};

    // find the first zero in the collection
    auto target = 0;
    auto firstZero = find(begin(v), end(v), target); // returning the poiter
    int weLookedFor;
    if (firstZero != end(v)) cout << "we looked for " << *firstZero << endl; // dereferencing the value of the pointer
    else cout << target << " is not found" << endl;

    // we can start looking from the result
    auto firstTwoAfterZero = find(firstZero, end(v), 2);
    if (firstTwoAfterZero != end(v)) cout << "we found the second " << *firstZero << endl;
    else cout << target << " is a single one" << endl;
    // find the first 'a'
    auto letter = find(begin(s), end(s), 'a');
    cout << "letter we searched for is " << *letter << endl;
 
    // find_if_not
    // find_first_of
    // search
    // find_end = search
    // search_n
    // adjacent_find

    // lambda that calculates oddness
    // find first odd value
    auto result = find_if(begin(v), end(v), isodd_func);
    cout << "the first odd in the collection: " << *result << endl;
 
    // find first even value
    result = find_if_not(begin(v), end(v), isodd_func);
    cout << "the first even in the collection: " << *result << endl;
 
    // find first prime number in collection 'v', where prime numbers are stored in primes 
    vector<int> primes{1, 2, 3, 5, 7, 11, 13};
    result = find_first_of(begin(v), end(v), begin(primes), end(primes));
    cout << "prime num found with fund_first_of: " << *result << endl;
    
    result = find_if(begin(v), end(v), isprime_funct);
    cout << "prime num found with find_if + lambda func: " << *result << endl;


    // search: searching for the first sequence
    vector<int> subsec{2, 4};
    result = search(begin(v), end(v), begin(subsec), end(subsec));
    weLookedFor = *result;
    result++;
    result++;
    int six = *result;

    string am = "am";
    letter = search(begin(s), end(s), begin(am), end(am));
    cout << "beging of " << am << " is " << *letter << endl;


    result = find_end(begin(v), end(v), begin(subsec), end(subsec));
    result++;
    result++;
    if (result != end(v))  cout << "right after the subsequence: " << *result << endl;

    // 2 is a number of consecutive matches
    // 4 is the value we are looking at
    // we are looking for two 4s in a row, e.g, [4, 4]
    target = 4;
    int num_conseq_matches = 2; // e.g, [4, 4]
    result = search_n(begin(v), end(v), 2, num_conseq_matches);
    result--;   // we have to step back once
    int two = *result;

    result = adjacent_find(begin(v), end(v));
    six = *result;
    result++;
    six = *result;

}

void counting(){
    std::vector<int> v{2, -7, 1, 2, 3, 4, 5, 6, -2, 4};

    // count
    // count how many entries have the target value 2
    int twos = 0;
    int const target = 2;

    for (size_t i = 0; i < v.size(); i++)
        if (v[i] == target) twos ++;

    twos = count(v.begin(), v.end(), target); // begin, end are member functions
    twos = count(begin(v), end(v), target);   // begin, end are nonmember function

    int odds = 0;
    // auto is int
    for (auto elem : v)
        if (elem % 2 != 0) odds++;


    // count_if (cournt if satisfying cond)

    odds = count_if(begin(v), end(v), [](int elem) { return elem % 2 != 0;});
    cout << "odds = " << odds << "\n";

    map<int, int> monthlengths{{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}};
    int longmonths = count_if(begin(monthlengths), end(monthlengths),
        [](pair<int, int> elem) {
            cout << "in month " << elem.first << " " << elem.second << " days" <<  endl;
            return elem.second  == 31;}
    );
    cout << "longmonths = " << longmonths << "\n";

    bool allof, noneof, anyof;
    allof  = (odds == v.size());
    noneof = (odds == 0);
    anyof  = (odds > 0);

    allof  = all_of(begin(v), end(v), [](auto elem){  return elem % 2 != 0;});
    noneof = none_of(begin(v), end(v), [](auto elem){  return elem % 2 != 0;});
    anyof  = any_of(begin(v), end(v), [](auto elem){  return elem % 2 != 0;});
    
}
