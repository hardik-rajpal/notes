#include<bits/stdc++.h>
using namespace std;
class intervalMap{
  map<int,int> m;
  int empty = 0;
  void append(int s, int e, int v){
    
  }
  void set(int s, int e, int v){
    auto stiter = m.lower_bound(s);
    if(stiter!=m.begin()){
      stiter--;
    }
    auto enditer = m.upper_bound(e);
    
  }
  
};
// #define ST_(x) #x
// #define ST(x) ST_(x)
// #define TT(x) std::cout << std::endl << ST(x) << std::endl ; (x)

// // this
// // https://codereview.stackexchange.com/questions/158341/an-interval-map-data-structure
// // refactored and hopefully simplified and improved
// namespace fub
// {
//   template <
//       typename Key,
//       typename T
//       /*
//       DBJ moved this to be public typedefs usabel by template definitions clients
//       typename Compare = std::less<Key>,
//       typename Allocator = std::allocator<std::pair<const Key, std::optional<T>>>
//       */
//   > class IntervalMap final /* DBJ added 'final' */
//   {
//       // DBJ -- typedef are to be public and thus used by the client code
//       // this is standard C++ standard convention
//       public:
//       // DBJ moved these two from template parameters so that client code can use them
//       // using Compare = std::less<Key>;
//       // using Allocator = std::allocator<std::pair<const Key, std::optional<T>>>;
//     // DBJ removed --> private:
//       // using map_type = std::map<Key, std::optional<T>, Compare, Allocator>;
//       using map_type = std::map<Key, T >;
//       map_type map_;
//       // DBJ 00: this much simplifies methods inside the template
//       using type = IntervalMap ;
      
//       // DBJ 01: using static_assert simplifies the code
//       // check the type requirements only once at compile time
//       // no need to mention them in every comment
//       static_assert(std::is_nothrow_default_constructible_v<map_type>);
//       static_assert(is_copy_constructible_v <T> ) ;
      
//      // DBJ removed --> public:
// /*
//       IntervalMap()
//       // DBJ removed. See DBJ 01 -- noexcept(std::is_nothrow_default_constructible_v<map_type>) 
//         : IntervalMap{Compare()}
//       {}

//       explicit
//       IntervalMap(const Compare& comp, const Allocator& alloc = Allocator())
//       // DBJ removed. See DBJ 01 -- noexcept(std::is_nothrow_default_constructible_v<map_type>) 
//         : map_{comp, alloc}
//       {}

//       IntervalMap(const IntervalMap&) = default;

//       IntervalMap(const IntervalMap& other, const Allocator& alloc)
//         : map_{other.map_, alloc}
//       {}

//       IntervalMap(IntervalMap&& other, const Allocator& alloc)
//       // DBJ removed. See DBJ 01 -- noexcept(std::is_nothrow_default_constructible_v<map_type>) 
//         : map_{std::move(other.map_), alloc}
//       {}
// */
//       /* DBJ 02: commented out -- reason: this is not necessary
//       ~IntervalMap() = default;
//       IntervalMap& operator=(const IntervalMap&) = default;
//       IntervalMap& operator=(IntervalMap&&) = default;
//       IntervalMap(IntervalMap&&) = default;
//        */
//       // ACCESSORS

//       //DBJ 03: commented out -- reasone: compiler will do the most efficient move/copy elision
//       // stanbdard C++ is based on value semantics
//       // no need to return by const reference
//       // const map_type&  std_map() const&   noexcept     { return map_; }
//       map_type  std_map() const  noexcept  { return map_; }

//       // DBJ 04: removed use of reference_wrapper -- reason:  see DBJ 03
//       // std::optional<std::reference_wrapper<const T>>
//       std::optional<T>
//       operator[](const Key& key) const // DBJ removed --> & 
//           // DBJ removed, see DBJ 01 -- noexcept(std::is_nothrow_callable_v<Compare(const Key&, const Key&)>)
//       {
//         auto ub = map_.upper_bound(key);
//         if (ub == map_.begin()) {
//           return {};
//         }
//         return (--ub)->second;
//       }

//       //DBJ 05: removed -- reason const & not necessary in standard C++
//       // const T & at(const Key& key) const&
//       T  at(Key key) const
//       {
//         auto ub = this->operator[](key);
//         if (!ub.has_value()) {
//           throw std::out_of_range {
//             "IntervalMap::at: index is out of bounds."
//           };
//         }
//         return *ub;
//       }

//       // CAPACITY

//       bool  empty() const  noexcept  { return map_.empty(); }

//       // MODIFIERS

//       /// \brief assigns a `value` to a given interval [lower, upper).
//       /// \note `T` needs to be `CopyConstructible` for `insert_upper_bound`
//       /// DBJ: no need to emphasize this in every comment, see DBJ 01
//       void
//       insert(Key lower, Key upper, T value)
//       {
//         if (!compare(lower, upper)) {
//           return;
//         }
//         auto last = insert_upper_bound(std::move(upper));
//         auto first = map_.lower_bound(lower);
//         map_.erase(first, last);
//         map_.insert(last, std::make_pair(std::move(lower), std::move(value)));
//       }

//       /// \brief removes all values in the given interval [lower, upper).
//       /// \note this requires that `T` is `CopyConstructible`
//       /// DBJ: no need to emphasize this in every comment, see DBJ 01
//       void
//       remove(Key lower_key, Key upper_key)
//       {
//         if (!compare(lower_key, upper_key)) {
//           return;
//         }
//            auto upper_ = map_.find(upper_key);
//            auto current_ = map_.find(lower_key);
//                while( (current_ != map_.end())  || (current_ != upper_ )) 
//                {
//                   auto next_ = next(current_);
//                       map_.erase(current_) ;
//                   current_ = next_ ;    
//                }
//            if(upper_ != map_.end())
//                     map_.erase(upper_);
//       }


//     private:
//       /// \brief compares to key values with maps comparator
//       /// DBJ: the comment above is completely confusing
//       // obvously jus two keys are compared, between  thmeselves
//       // also and again const references are not an optimization 
//       // bool  compare(const Key& lhs, const Key& rhs) const
//       // as this is standard C++
//       // also DBJ -- see DBJ 01 -- noexcept(std::is_nothrow_callable_v<Compare(Key, Key)>)
//       bool  compare(Key lhs, Key rhs) const
//       { 
//           // DBJ removed --> return std::invoke(map_.key_comp(), lhs, rhs); 
//           // we have defined the Compare type in the template prologue
//           // although it is not clear why? 
//           return lhs < rhs ;
//       }

//       /// \brief inserts an upper bound such that super sets are valid
//       /// \note this is a helper function for `insert()`
//       /// \note `T` needs to be `CopyConstructible`
//       /// DBJ: no need to emphasize this in every comment, see DBJ 01
//       /// DBJ removed the use of r-refernce -- auto insert_upper_bound(Key&& upper)
//       auto insert_upper_bound(Key upper)
//       {
//         auto last = map_.upper_bound(upper);
//         if (last == map_.begin()) {
//           return map_.insert(last, std::make_pair(std::move(upper), std::optional<T>{}));
//         }
//         auto&& value_before = std::prev(last)->second;
//         return map_.insert(last, std::make_pair(std::move(upper), value_before));
//       }

//       /// \brief tests if there is a value at the given position.
//       /// \note iterator has to be deferencable
//       bool  has_value(typename map_type::const_iterator iterator) const  noexcept
//       { 
//       return iterator->second.has_value(); 
//       }

//       /// \brief erases the iterator if it points to an empty optional.
//       /// \note if the optional is empty the iterator is a pure upper bound.
//       /// \note this function is a helper function for `remove()`
//       void erase_if_empty(typename map_type::const_iterator iterator)  noexcept
//       {
//       /*
//       DBJ commented out
//         if (iterator != map_.end() && !has_value(iterator)) {
//           map_.erase(iterator);
//        */
//         if (iterator == map_.end() ) return ;
//         if ( has_value(iterator) ) return ;
//           map_.erase(iterator);
//       }
    
//     // DBJ moved these two in here and made them friends
// friend  bool operator==( const type & lhs, const type & rhs)
//     {
//       return lhs.map() == rhs.map();
//     }

// friend  bool operator!=( const type & lhs, const type & rhs)
//     {
//       return ! ( lhs.map() == rhs.map() );
//     }
    
//   }; // DBJ added comment --> eof IntervalMap
// /*
// DBJ commented out -- reason -- 1. these are much simple if made as friend's to the IntervalMap
//                                2. they both need not have full implementeation  as not_eqauls
//                                   is ! equals ... see above 
//   template <typename Key, typename T, typename Comp, typename Allocator>
//     bool operator==(
//         const IntervalMap<Key, T, Comp, Allocator>& lhs,
//         const IntervalMap<Key, T, Comp, Allocator>& rhs)
//     {
//       return lhs.map() == rhs.map();
//     }

//   template <typename Key, typename T, typename Comp, typename Allocator>
//     bool operator!=(
//         const IntervalMap<Key, T, Comp, Allocator>& lhs,
//         const IntervalMap<Key, T, Comp, Allocator>& rhs)
//     {
//       return lhs.map() != rhs.map();
//     }
// */
// } // DBJ added comment -> eof namespace 

// // void print(std::ostream& out, const std::map<int, std::optional<std::string>>& map)
// // DBH changed to std ostream operator handling the required map type
// std::ostream& operator << (std::ostream& out, const std::map<int, std::string>& map)
// {
//   for (auto&& [key, mapped] : map)
//   {
//     out << '{' << key << ", ";
//     if (mapped.size()) {
//       out << mapped;
//     } else {
//       out << "{}";
//     }
//     out << "}\n";
//   }
//   out << '\n';
//     return out ;
// }

// // DBJ added
// using fub_interval_map_type = fub::IntervalMap<int, string> ;

// std::ostream& operator << (std::ostream& out, const fub_interval_map_type & fub_map)
// {
//     return out << fub_map.std_map();
// }

// int main()
// {
//   cout << boolalpha;
//   auto map = fub_interval_map_type{} ;

//  TT(map.insert(0, 10, "foo"));
//   cout << map << "map.at(0) = " << map.at(0) << '\n';
//   cout << "map[10].has_value() = " << map[10].has_value() << "\n\n";

//   TT(map.insert(3, 7, "bar"));
//   cout <<  map << "map.at(5) = " << map.at(5) << "\n\n";

//   TT(map.remove(2, 8));
//   cout <<  map << "map[5].has_value() = " << map[5].has_value() << '\n';
// }
