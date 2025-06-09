//orderi429@gmail.com
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <functional>

namespace container{

    /**
    * @brief A dynamic container for elements supporting comparison.
    * Provides methods to add and remove elements, query its size, and print contents.
    * Also contains iterator classes .
    */
    template<typename T = int> class MyContainer{

        private:
            // storage of elements
            std::vector<T> arr;
        
        public:
            /**
            * @brief Add an element to the container.
            */
            void add(const T& x){
                arr.push_back(x);
            }

            /**
            * @brief Remove all occurrences of an element from the container.
            * @param x The element to remove.
            * @throws std::runtime_error if the element is not found.
            */
            void remove(const T& x){
                auto cnt = std::count(arr.begin(), arr.end(), x);
                if (cnt == 0) {
                    throw std::runtime_error("Element not found in container");
                }
                arr.erase(std::remove(arr.begin(), arr.end(), x), arr.end());
            }
            /**
            * @brief Get the number of elements in the container.
            */
            int size()const {
                return static_cast<int>(arr.size());
            }
            
            /**
            * @brief Output the container contents in a readable format.
            * @param os Output stream.
            * @param c  The container to print.
            * @return Reference to the output stream.
            */
            friend std::ostream& operator<<(std::ostream& os, const MyContainer<T>& c) {
                os << "[";
                for (std::size_t i = 0; i < c.arr.size(); ++i) {
                    os << c.arr[i];
                    if (i + 1 < c.arr.size()) os << ", ";
                }
                os << "]";
                return os;
            }

            /**
            * @brief Iterator to traverse elements in ascending order.
            */
            class AscendingOrder {

                private:
                    MyContainer<T>* container;   // Pointer to the container being iterated
                    std::vector<T> sorted;    // Sorted copy of elements
                    std::size_t index;      // Current position in iteration

                    /**
                    * @brief Prepare the sorted copy in ascending order.
                    */
                    void sortedContainer() {
                        sorted = container->arr;
                        std::sort(sorted.begin(), sorted.end());
                    }

                public:

                    /**
                    * @brief Construct ascending iterator .
                    * @param c Reference to the container.
                    * @param x Initial index in sorted sequence.
                    */
                    AscendingOrder (MyContainer<T> & c ,std::size_t x){
                        this->container =  &c;
                        this->index = x;
                        sortedContainer();
                    }

                    /**
                    * @brief Access the current element.
                    * @return Constant reference to the element.
                    * @throws std::out_of_range if index is invalid.
                    */
                    const T& operator*()const {
                        if(index >= sorted.size()){
                            throw std::out_of_range("AscendingOrder out of range");
                        }
                        return sorted[index];
                    } 

                    /**
                    * @brief move to next element.
                    * @return Reference to this iterator.
                    * @throws std::out_of_range if incrementing past end.
                    */
                    AscendingOrder& operator++() {
                        if (index >= sorted.size()){
                            throw std::out_of_range("Cannot increment past end");
                        }
                        ++index;
                        return *this;
                    }

                    /**
                    * @brief Compare two ascending iterators for equality.
                    * @param o Other iterator.
                    * @return True if both point to same container and index.
                    */
                    bool operator==(const AscendingOrder& o) const {
                        return container == o.container && index == o.index;
                    }
                    /**
                    * @brief Compare two ascending iterators for inequality.
                    * @param o Other iterator.
                    * @return True if containers or indices differ.
                    */
                    bool operator!=(const AscendingOrder& o) const {
                        return !(*this == o);
                    }

                    /**
                    * @brief Get beginning ascending iterator.
                    * @param cont Reference to the container.
                    * @return AscendingOrder at index 0.
                    */
                    static AscendingOrder begin(MyContainer<T>& cont) {
                        return AscendingOrder(cont, 0);
                    }
                    /**
                    * @brief Get end ascending iterator.
                    * @param cont Reference to the container.
                    * @return AscendingOrder at index size.
                    */
                    static AscendingOrder end(MyContainer<T>& cont) {
                        return AscendingOrder(cont, cont.size());
                    }
                
            };


                
            //====================================================================================================================
            //---------------------------------------------------- DescendingOrder-----------------------------------------------------------------
            //============================================================================================================================
            
            /**
            * @brief Iterator to traverse elements in descending order.
            */
            class DescendingOrder{
                private:
                    MyContainer<T>* container;
                    std::vector<T> sorted;
                    std::size_t index;
                    
                    void sortedContainer() {
                        sorted = container->arr;
                        std::sort(sorted.begin(), sorted.end(), std::greater<T>());
                    }

                public:

                    /**
                    * @brief Construct descending iterator.
                    * @param c Reference to the container.
                    * @param x Initial index in sorted sequence.
                    */
                    DescendingOrder (MyContainer<T> & c ,std::size_t x){
                        this->container =  &c;
                        this->index = x;
                        sortedContainer();
                    }
                    
                    /**
                    * @brief Access the current element in descending order.
                    * @return Constant reference to the element.
                    * @throws std::out_of_range if index is invalid.
                    */
                    const T& operator*()const {
                        if(index >= sorted.size()){
                            throw std::out_of_range(" DescendingOrder out of range");
                        }
                        return sorted[index];
                    } 

                    /**
                    * @brief move to next element.
                    * @return Reference to this iterator.
                    * @throws std::out_of_range if incrementing past end.
                    */
                    DescendingOrder& operator++() {
                        if (index >= sorted.size()){
                            throw std::out_of_range("Cannot increment past end");
                        }
                        ++index;
                        return *this;
                    }


                    /**
                    * @brief Compare two ascending iterators for equality.
                    * @param o Other iterator.
                    * @return True if both point to same container and index.
                    */
                    bool operator==(const DescendingOrder& o) const {
                        return container == o.container && index == o.index;
                    }
                    /**
                    * @brief Compare two ascending iterators for inequality.
                    * @param o Other iterator.
                    * @return True if containers or indices differ.
                    */
                    bool operator!=(const DescendingOrder& o) const {
                        return !(*this == o);
                    }

                    /**
                    * @brief Get beginning ascending iterator.
                    * @param cont Reference to the container.
                    * @return DescendingOrder at index 0.
                    */
                    static DescendingOrder begin(MyContainer<T>& cont) {
                        return DescendingOrder(cont, 0);
                    }
                    /**
                    * @brief Get end ascending iterator.
                    * @param cont Reference to the container.
                    * @return DescendingOrder at index size().
                    */
                    static DescendingOrder end(MyContainer<T>& cont) {
                        return DescendingOrder(cont, cont.size());
                    }
                
            };

            //=========================================================================================================================
            //---------------------------------------------------- SideCrossOrder-------------------------------------------------------------------
            //====================================================================================================================

            /**
            * @brief Iterator to traverse elements in a side cross pattern.
            * Starts with the smallest element, then the largest, then the next smallest,
            * then the next largest and so on.
            */
            class SideCrossOrder{
                private:
                    MyContainer<T>* container;
                    std::vector<T> sorted;
                    std::size_t index;
                    
                    /**
                    * @brief Prepare a sorted copy of the container’s contents.
                    * The copy is sorted in descending order so that:
                    * even indices pick from the back ,smallest remaining
                    * odd indices pick from the front ,largest remaining
                    */
                    void sortedContainer() {
                        sorted = container->arr;
                        std::sort(sorted.begin(), sorted.end(), std::greater<T>());
                    }

                public:

                    /**
                    * @brief Construct a SideCrossOrder iterator at a given position.
                    * @param c  Reference to the container to iterate.
                    * @param x  Initial index in the side cross sequence.
                    */
                    SideCrossOrder (MyContainer<T> & c ,std::size_t x){
                        this->container =  &c;
                        this->index = x;
                        sortedContainer();
                    }


                    /**
                    * @brief Access the current element in the side-cross traversal.
                    * even indices pick from the back ,smallest remaining
                    * odd indices pick from the front ,largest remaining
                    * @return Constant reference to the element at the current sequence position.
                    * @throws std::out_of_range if `index` is beyond the number of elements.
                    */
                    const T& operator*()const {
                        if(index >= sorted.size()){
                            throw std::out_of_range(" SideCrossOrder out of range");
                        }

                        if(index % 2 == 1){
                            return sorted[index/2];
                        }
                        else{
                            return sorted[sorted.size() -1 -(index/2)];
                        }
                    } 

                    /**
                    * @brief Advance to the next position in the side cross sequence.
                    * @return Reference to this iterator after increment.
                    * @throws std::out_of_range if incrementing past the last element.
                    */
                    SideCrossOrder& operator++() {
                        if (index >= sorted.size()){
                            throw std::out_of_range("Cannot increment past end");
                        }
                        ++index;
                        return *this;
                    }

                    /**
                    * @brief Compare two SideCrossOrder iterators for equality.
                    * @param o  Other iterator to compare.
                    * @return True if both refer to the same container and same index.
                    */
                    bool operator==(const SideCrossOrder& o) const {
                        return container == o.container && index == o.index;
                    }
                    /**
                    * @brief Compare two SideCrossOrder iterators for inequality.
                    * @param o  Other iterator to compare.
                    * @return True if they differ by container or index.
                    */
                    bool operator!=(const SideCrossOrder& o) const {
                        return !(*this == o);
                    }

                    /**
                    * @brief Get an iterator to the first element.
                    * @param cont  Reference to the container.
                    * @return SideCrossOrder at index 0.
                    */
                    static SideCrossOrder begin(MyContainer<T>& cont) {
                        return SideCrossOrder(cont, 0);
                    }
                    
                    /**
                    * @brief Get an iterator just past the last element.
                    * @param cont  Reference to the container.
                    * @return SideCrossOrder at index size.
                    */
                    static SideCrossOrder end(MyContainer<T>& cont) {
                        return SideCrossOrder(cont, cont.size());
                    }
                
            };

                
            //===============================================================================================================================
            //---------------------------------------------------- ReverseOrder-------------------------------------------------------------------
            //============================================================================================================================
            
            
            /**
             * @brief Iterator to traverse elements in reverse insertion order.
             */
            class ReverseOrder{
                private:
                    MyContainer<T>* container;
                    std::vector<T> sorted;
                    std::size_t index;
                    
                    /**
                    * @brief Prepare a reversed copy of the container’s contents.
                    */
                    void sortedContainer() {
                        sorted = container->arr;
                        std::reverse(sorted.begin(), sorted.end());
                    }

                public:
                    /**
                    * @brief Construct a ReverseOrder iterator at a given index.
                    * @param c  Reference to the container to iterate.
                    * @param x  Initial index in the reversed sequence.
                    */
                    ReverseOrder (MyContainer<T> & c ,std::size_t x){
                        this->container =  &c;
                        this->index = x;
                        sortedContainer();
                    }

                    /**
                    * @brief Access the current element in reverse order.
                    * @return Constant reference to the element at the current index.
                    * @throws std::out_of_range if index is beyond the number of elements.
                    */
                    const T& operator*()const {
                        if(index >= sorted.size()){
                            throw std::out_of_range(" ReverseOrder out of range");
                        }
                        return sorted[index];
                    } 


                    /**
                    * @brief  move to the next element in reverse sequence.
                    * @return Reference to this iterator after increment.
                    * @throws std::out_of_range if incrementing past the last element.
                    */
                    ReverseOrder& operator++() {
                        if (index >= sorted.size()){
                            throw std::out_of_range("Cannot increment past end");
                        }
                        ++index;
                        return *this;
                    }

                    /**
                    * @brief Compare two ReverseOrder iterators for equality.
                    * @param o  Other iterator to compare.
                    * @return True if both refer to the same container and same index.
                    */
                    bool operator==(const ReverseOrder& o) const {
                        return (container == o.container && index == o.index);
                    }
                    /**
                    * @brief Compare two ReverseOrder iterators for inequality.
                    * @param o  Other iterator to compare.
                    * @return True if container or index differ.
                    */
                    bool operator!=(const ReverseOrder& o) const {
                        return !(*this == o);
                    }

                    /**
                    * @brief Get an iterator to the first element in reverse order.
                    * @param c  Reference to the container.
                    * @return ReverseOrder at index 0.
                    */
                    static ReverseOrder begin(MyContainer<T>& c) {
                        return ReverseOrder(c, 0);
                    }
                    /**
                    * @brief Get an iterator just past the last element in reverse order.
                    * @param c  Reference to the container.
                    * @return ReverseOrder at index size.
                    */
                    static ReverseOrder end(MyContainer<T>& c) {
                        return ReverseOrder(c, c.size());
                    }
                
            };

            //===============================================================================================================================
            //---------------------------------------------------- Order-------------------------------------------------------------------
            //============================================================================================================================
            
            /**
            * @brief Iterator to traverse elements in insertion order.
            */
            class Order{
                private:
                    MyContainer<T>* container;
                    std::vector<T> sorted;
                    std::size_t index;
       
                    /**
                    * @brief Prepare a copy of the container contents.
                    * This simply copies the underlying vector without reordering.
                    */
                    void sortedContainer() {
                        sorted = container->arr;
                    }

                public:

                    /**
                    * @brief Construct an Order iterator at a specified index.
                    * @param c  Reference to the container to iterate.
                    * @param x  Starting index in the sequence.
                    */
                    Order (MyContainer<T> & c ,std::size_t x){
                        this->container =  &c;
                        this->index = x;
                        sortedContainer();
                    }


                    /**
                    * @brief Access the current element in insertion order.
                    * @return Constant reference to the element at the current index.
                    * @throws std::out_of_range if index is outside the valid range.
                    */
                    const T& operator*()const {
                        if(index >= sorted.size()){
                            throw std::out_of_range(" Order out of range");
                        }
                        return sorted[index];
                    } 


                    /**
                    * @brief move to the next element.
                    * @return Reference to this iterator after increment.
                    * @throws std::out_of_range if incrementing past the last element.
                    */
                    Order& operator++() {
                        if (index >= sorted.size()){
                            throw std::out_of_range("Cannot increment past end");
                        }
                        ++index;
                        return *this;
                    }


                    /**
                    * @brief Compare two Order iterators for equality.
                    * @param o  Other iterator to compare.
                    * @return True if both refer to the same container and same index.
                    */
                    bool operator==(const Order& o) const {
                        return (container == o.container && index == o.index);
                    }
                    /**
                    * @brief Compare two Order iterators for inequality.
                    * @param o  Other iterator to compare.
                    * @return True if container or index differ.
                    */
                    bool operator!=(const Order& o) const {
                        return !(*this == o);
                    }

                    /**
                    * @brief Get iterator to the first element .
                    * @param c Reference to the container.
                    * @return Order at index 0.
                    */
                    static Order begin(MyContainer<T>& c) {
                        return Order(c, 0);
                    }
                    /**
                    * @brief Get iterator just past the last element
                    * @param cont  Reference to the container.
                    * @return Order at index size.
                    */
                    static Order end(MyContainer<T>& c) {
                        return Order(c, c.size());
                    }
                
            };

            //===============================================================================================================================
            //---------------------------------------------------- MiddleOutOrder-------------------------------------------------------------------
            //============================================================================================================================        
            
            /**
             * @brief Iterator to traverse elements starting from the middle and alternating outward.
             * Visits the element at the middle index first, then one left, then one right,
             * then two left, two right, and so on.
             */
            class MiddleOutOrder{
                private:
                    MyContainer<T>* container;
                    std::vector<T> snapshot;
                    std::size_t index;  // Current step in the middle-out sequence
                    std::size_t mid;  //Precomputed middle index of snapshot

                    /**
                    * @brief Compute the real position in the snapshot for a given step.
                    * @param idx  The sequence step .
                    * @return The actual index in snapshot.
                    */
                    std::size_t calcPos(std::size_t idx) const {

                        if (idx == 0) {
                            return mid;
                        }
                        if (idx % 2 == 1) {
                            std::size_t step = (idx + 1) / 2;    
                            return mid - step;
                        }
                        else{
                            std::size_t step = idx / 2;             
                            return mid + step;
                        }
                    }
    
                public:

                    /**
                    * @brief Construct a MiddleOutOrder iterator.
                    * @param c  Reference to the container to iterate.
                    * @param x  Initial sequence step.
                    */
                    MiddleOutOrder (MyContainer<T> & c ,std::size_t x){
                        this->container =  &c;
                        this->index = x;
                        snapshot = c.arr;

                        if (snapshot.size() == 0) {
                            mid = 0;  
                        } else {
                            mid = snapshot.size() / 2;
                        }
                    }

                    /**
                    * @brief Access the current element in the middle-out traversal.
                    * @return Constant reference to the element.
                    * @throws std::out_of_range if index is beyond the number of elements.
                    */
                    const T& operator*()const {
                        if(index >= snapshot.size()){
                            throw std::out_of_range(" MiddleOutOrder out of range");
                        }
                        std::size_t pos = calcPos(index);
                        return snapshot[pos];
                    } 
            
                    /**
                    * @brief advance to the next position in the sequence.
                    * @return Reference to this iterator after increment.
                    * @throws std::out_of_range if incrementing past the last element.
                    */
                    MiddleOutOrder& operator++() {
                        if (index >= snapshot.size()){
                            throw std::out_of_range("Cannot increment past end");
                        }
                        ++index;
                        return *this;
                    }
    
                    /**
                    * @brief Compare two middle-out iterators for equality.
                    * @param o  Other iterator.
                    * @return True if both refer to the same container and same sequence step.
                    */
                    bool operator==(const MiddleOutOrder& o) const {
                        return (container == o.container && index == o.index);
                    }
                    /**
                    * @brief Compare two middle-out iterators for inequality.
                    * @param o  Other iterator.
                    * @return True if they differ by container or sequence step.
                    */
                    bool operator!=(const MiddleOutOrder& o) const {
                        return !(*this == o);
                    }

                    /**
                    * @brief Get iterator at the start of the middle-out sequence.
                    * @param c  Reference to the container.
                    * @return MiddleOutOrder at step 0.
                    */
                    static MiddleOutOrder begin(MyContainer<T>& c) {
                        return MiddleOutOrder(c, 0);
                    }
                    /**
                    * @brief Get iterator just past the last element in the sequence.
                    * @param c  Reference to the container.
                    * @return MiddleOutOrder at step size.
                    */
                    static MiddleOutOrder end(MyContainer<T>& c) {
                        return MiddleOutOrder(c, c.size());
                    } 
                };         
    };
}