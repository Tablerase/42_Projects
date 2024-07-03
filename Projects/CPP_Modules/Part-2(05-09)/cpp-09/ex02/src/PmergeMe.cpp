/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:30:57 by rcutte            #+#    #+#             */
/*   Updated: 2024/07/02 14:08:06 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ================================  Header ================================= */

#include "../include/PmergeMe.hpp"

/* ======================== Constructor / Destructor ======================== */

PmergeMe::PmergeMe()
{
  #ifdef LOG
  std::cout << BLUB << "📘 Constructor PmergeMe by default" << RESET << "\n";
  #endif
  vector_init_ = 0;
  vector_sort_ = 0;
  deque_init_ = 0;
  deque_sort_ = 0;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
  *this = other;
  #ifdef LOG
  std::cout << BLUB << "📘 Constructor Pmerge by copy" << RESET << "\n";
  #endif
}

PmergeMe::~PmergeMe(){
  #ifdef LOG
  std::cout << BLKB << "📘‍ Destructor PmergeMe by default" << RESET << "\n";
  #endif
}

/* ================================ Operator ================================ */

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
  #ifdef LOG
  std::cout << BLUB << "📘 Constructor PmergeMe by assign" << RESET << "\n";
  #endif
  if (this != &rhs){
    origin_array_ = rhs.origin_array_;
    vector_array_ = rhs.vector_array_;
    deque_array_ = rhs.deque_array_;
    vector_init_ = rhs.vector_init_;
    vector_sort_ = rhs.vector_sort_;
    deque_init_ = rhs.deque_init_;
    deque_sort_ = rhs.deque_sort_;
  }
  return *this;
}

/* ================================= Getter ================================= */

std::vector<int> PmergeMe::get_vector() const {
  return this->vector_array_;
}

std::deque<int> PmergeMe::get_deque() const {
  return this->deque_array_;
}

std::vector<int> PmergeMe::get_origin() const {
  return this->origin_array_;
}

long PmergeMe::get_vector_time() const {
  return this->vector_init_ + this->vector_sort_;
}

long PmergeMe::get_deque_time() const {
  return this->deque_init_ + this->deque_sort_;
}

/* ================================= Setter ================================= */

void PmergeMe::set_origin(std::vector<int> input){
  origin_array_ = input;
}

void PmergeMe::set_vector(std::vector<int> input){
  vector_array_ = input;
}

void PmergeMe::set_time_vector_init(long time){
  vector_init_ = time;
}

void PmergeMe::set_time_vector_sort(long time){
  vector_sort_ = time;
}

void PmergeMe::set_deque(std::deque<int> input){
  deque_array_ = input;
}

void PmergeMe::set_time_deque_init(long time){
  deque_init_ = time;
}

void PmergeMe::set_time_deque_sort(long time){
  deque_sort_ = time;
}

/* ================================ Function ================================ */

/**
 * @brief Jacobsthal set calculation
 * @param index : position in the set
 * @note Jn = Jn-1 + 2 x Jn-2
 */
// static int jacobsthal(int index){
//   if (index == 0)
//     return 0;
//   if (index == 1)
//     return 1;
//   return jacobsthal(index - 1) + 2 * jacobsthal(index - 2);
// }

bool PmergeMe::isSorted(const std::vector<int>& vec) {
  return std::adjacent_find(vec.begin(), vec.end(), std::greater<int>()) == vec.end();
}

bool PmergeMe::isSorted(const std::deque<int>& deq) {
  return std::adjacent_find(deq.begin(), deq.end(), std::greater<int>()) == deq.end();
}

/* Vector */

/**
 * @brief BinarySearch
 * @param main : vector in witch to search
 * @param value : value to find (find the best position to insert)
 * @return position to insert the value into the vector
 */
static int BinarySearch(std::vector<int>& main, int& value){
  int left = 0;
  int right = main.size() - 1;
  int middle;
  while (left <= right)
  {
    middle = floor( (left + right) / 2 );
    if (main[middle] < value){
      left = middle + 1;
    } else if (main[middle] > value){
      right = middle - 1;
    } else {
      return middle;
    }
  }
  return right;
}

/**
 * @brief BinaryInsertionSort
 * @note Use jacobsthal to group pending elements into groups
 * with each group size according to jacobshtal sequence.
 * Then bin seach is use to find where to insert each element form max to
 * min of each group
*/
static void BinaryInsertSort(std::vector<int>& main, std::vector<int>& pending){
  // Jacobstahl sequence
  int jacob_seq[] = {
    0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845,
    43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811,
    22369621, 44739243, 89478485, 178956971, 357913941, 715827883
  };
  #ifdef LOG
  int jacob_seq_size = 33;
  std::cout
    << CYNB << std::setw(16) << "Jacobsthal " << RESET << " ";
  for (int i = 0; i < jacob_seq_size - 1; ++i) {
    std::cout << jacob_seq[i] << ", ";
  }
  std::cout << std::endl;
  #endif
  // Insert Sort
    // Use jacobsthal to group pending elements into groups
    // with each group size according to jacobshtal sequence
    // Then bin seach is use to find where to insert each element form max to
    // min of each group
  int value = 0;
  int group_step = 0;
  std::vector<int>::reverse_iterator it;
  std::vector<int>::reverse_iterator it_group_rbegin = pending.rend();
  std::vector<int>::reverse_iterator it_group_rend = pending.rend();
  // loop over pending array
  size_t i = 0;
  while (i < pending.size()) {
    // Setup group with jacobsthal set
    it_group_rend = it_group_rbegin;
    if (i + jacob_seq[group_step] < pending.size() - 1) {
      it_group_rbegin = it_group_rend - jacob_seq[group_step];
    } else {
      it_group_rbegin = pending.rbegin();
    }
    // find which element to insert (by inverted dir in each jacob group)
    for (it = it_group_rbegin; it != it_group_rend; it++) {
      // value to insert
      value = *it;
      // use bin search to know where to insert
      int insert_position = BinarySearch(main, value);
      try {
      // insert into main chain
        main.insert(main.begin() + insert_position + 1, value);
      } catch (std::out_of_range) {
        main.insert(main.begin() + insert_position, value);
      }
      i++;
    }
    group_step++;
  }
  #ifdef LOG
  std::cout
    << YELB << std::setw(16) << " Post Insert " << RESET << " ";
  for (size_t i = 0; i < main.size(); ++i) {
    std::cout << main[i] << " | ";
  }
  std::cout << std::endl;
  #endif
}

static void Merge(std::vector<std::pair<int, int> >& vec, int start, int mid, int end) {
  int i, j, k;
  int left_size = mid - start + 1;
  int right_size = end - mid;

  // Create subvectors
  std::vector< std::pair<int, int> > Left(left_size);
  std::vector< std::pair<int, int> > Right(right_size);
  // Copy values into subvectors
  for (i = 0; i < left_size; i++)
    Left[i] = vec[start + i];
  for (j = 0; j < right_size; j++)
    Right[j] = vec[mid + 1 + j];
  /* Until we reach end of Left or Right place element into the correct position inside
  parent vector */
  i = 0;
  j = 0;
  k = start;
  while (i < left_size && j < right_size) {
    if (Left[i] <= Right[j]) {
        vec[k] = Left[i];
        i++;
    } else {
        vec[k] = Right[j];
        j++;
    }
    k++;
  }
  /* Add remaining element into parent vector */
  while (i < left_size) {
    vec[k] = Left[i];
    i++;
    k++;
  }
  while (j < right_size) {
    vec[k] = Right[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
static void MergeSort(std::vector<std::pair<int, int> >& vec, int start, int end) {
  if (start < end) {
    // Split vector into 2 subvector
    int mid = start + (end - start) / 2;
    MergeSort(vec, start, mid);
    MergeSort(vec, mid + 1, end);
    // Merge sorted arrays
    Merge(vec, start, mid, end);
  }
}

void PmergeMe::SortVector(){
  if (this->vector_array_.empty() == true){ throw PmergeMe::Uninitialized_array(); }
  // ⏰ Start Sort Time
  struct timeval start, end;
  gettimeofday(&start, NULL);
  // Pair values (odd value stored alone with int max)
  std::vector< std::pair<int, int> > paired_vector;
  for (size_t i = 0; i < vector_array_.size(); i += 2) {
    if (vector_array_.size() % 2 != 0 && i >= vector_array_.size() - 2) {
      paired_vector.push_back(std::make_pair(std::numeric_limits<int>::max(), vector_array_[i]));
    } else {
      paired_vector.push_back(std::make_pair(vector_array_[i], vector_array_[i + 1]));
    }
  }
  #ifdef LOG
  std::cout
    << YELB << std::setw(16) << " Paired " << RESET << " ";
  for (size_t i = 0; i < paired_vector.size(); ++i) {
    std::cout << paired_vector[i].first << "," << paired_vector[i].second << " | ";
  }
  std::cout << std::endl;
  #endif

  // Sort each pair (ascending order)
  for (size_t i = 0; i < paired_vector.size(); ++i) {
    if (origin_array_.size() % 2 != 0 && i == paired_vector.size() - 1) {
      continue;
    } else if (paired_vector[i].second < paired_vector[i].first) {
      std::swap(paired_vector[i].first, paired_vector[i].second);
    }
  }
  #ifdef LOG
  std::cout
    << YELB << std::setw(16) << " Each pair sort " << RESET << " ";
  for (size_t i = 0; i < paired_vector.size(); ++i) {
    std::cout << paired_vector[i].first << "," << paired_vector[i].second << " | ";
  }
  std::cout << std::endl;
  #endif

  // Recursively sort the paired_vector (in ascending order)
  MergeSort(paired_vector, 0, paired_vector.size() - 1);
  #ifdef LOG
  std::cout
    << YELB << std::setw(16) << " Sorted Pair " << RESET << " ";
  for (size_t i = 0; i < paired_vector.size(); ++i) {
    std::cout << paired_vector[i].first << "," << paired_vector[i].second << " | ";
  }
  std::cout << std::endl;
  #endif

  // Separate Main Chain (pair[0]) and Pending Chain (pair[1])
  std::vector<int> main_chain;
  std::vector<int> pending_chain;
  for (size_t i = 0; i < paired_vector.size(); ++i) {
    if (origin_array_.size() % 2 != 0 && i == paired_vector.size() - 1) {
      pending_chain.push_back(paired_vector[i].second);
    } else {
      main_chain.push_back(paired_vector[i].first);
      pending_chain.push_back(paired_vector[i].second);
    }
  }
  #ifdef LOG
  std::cout
    << YELB << std::setw(16) << " Main Chain " << RESET << " ";
  for (size_t i = 0; i < main_chain.size(); ++i) {
    std::cout << main_chain[i] << " | ";
  }
  std::cout << std::endl;
  std::cout
    << YELB << std::setw(16) << " Pending Chain " << RESET << " ";
  for (size_t i = 0; i < pending_chain.size(); ++i) {
    std::cout << pending_chain[i] << " | ";
  }
  std::cout << std::endl;
  #endif

  // Bin Insert sort with Jacobsthal numbers (to reduce amount of comparison
  // thanks to order of jacobsthal numbers)
  BinaryInsertSort(main_chain, pending_chain);

  // Save sorted array
  vector_array_ = main_chain;
  // ⏰ Stop time vector sort
  gettimeofday(&end, NULL);
  long seconds = end.tv_sec - start.tv_sec;
  long micros = (seconds * 1000000) + end.tv_usec - start.tv_usec;
  set_time_vector_sort(micros);
}

/* deque */

/**
 * @brief BinarySearch
 * @param main : deque in witch to search
 * @param value : value to find (find the best position to insert)
 * @return position to insert the value into the deque
 */
static int BinarySearch(std::deque<int>& main, int& value){
  int left = 0;
  int right = main.size() - 1;
  int middle;
  while (left <= right)
  {
    middle = floor( (left + right) / 2 );
    if (main[middle] < value){
      left = middle + 1;
    } else if (main[middle] > value){
      right = middle - 1;
    } else {
      return middle;
    }
  }
  return right;
}

/**
 * @brief BinaryInsertionSort
 * @note Use jacobsthal to group pending elements into groups
 * with each group size according to jacobshtal sequence.
 * Then bin seach is use to find where to insert each element form max to
 * min of each group
*/
static void BinaryInsertSort(std::deque<int>& main, std::deque<int>& pending){
  // Jacobstahl sequence
  int jacob_seq[] = {
    0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845,
    43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811,
    22369621, 44739243, 89478485, 178956971, 357913941, 715827883
  };
  // Insert Sort
    // Use jacobsthal to group pending elements into groups
    // with each group size according to jacobshtal sequence
    // Then bin seach is use to find where to insert each element form max to
    // min of each group
  int value = 0;
  int group_step = 0;
  std::deque<int>::reverse_iterator it;
  std::deque<int>::reverse_iterator it_group_rbegin = pending.rend();
  std::deque<int>::reverse_iterator it_group_rend = pending.rend();
  // loop over pending array
  size_t i = 0;
  while (i < pending.size()) {
    // Setup group with jacobsthal set
    it_group_rend = it_group_rbegin;
    if (i + jacob_seq[group_step] < pending.size() - 1) {
      it_group_rbegin = it_group_rend - jacob_seq[group_step];
    } else {
      it_group_rbegin = pending.rbegin();
    }
    // find which element to insert (by inverted dir in each jacob group)
    for (it = it_group_rbegin; it != it_group_rend; it++) {
      // value to insert
      value = *it;
      // use bin search to know where to insert
      int insert_position = BinarySearch(main, value);
      try {
      // insert into main chain
        main.insert(main.begin() + insert_position + 1, value);
      } catch (std::out_of_range) {
        main.insert(main.begin() + insert_position, value);
      }
      i++;
    }
    group_step++;
  }
}

static void Merge(std::deque<std::pair<int, int> >& vec, int start, int mid, int end) {
  int i, j, k;
  int left_size = mid - start + 1;
  int right_size = end - mid;

  // Create subdeques
  std::deque< std::pair<int, int> > Left(left_size);
  std::deque< std::pair<int, int> > Right(right_size);
  // Copy values into subdeques
  for (i = 0; i < left_size; i++)
    Left[i] = vec[start + i];
  for (j = 0; j < right_size; j++)
    Right[j] = vec[mid + 1 + j];
  /* Until we reach end of Left or Right place element into the correct position inside
  parent deque */
  i = 0;
  j = 0;
  k = start;
  while (i < left_size && j < right_size) {
    if (Left[i] <= Right[j]) {
        vec[k] = Left[i];
        i++;
    } else {
        vec[k] = Right[j];
        j++;
    }
    k++;
  }
  /* Add remaining element into parent deque */
  while (i < left_size) {
    vec[k] = Left[i];
    i++;
    k++;
  }
  while (j < right_size) {
    vec[k] = Right[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
static void MergeSort(std::deque<std::pair<int, int> >& vec, int start, int end) {
  if (start < end) {
    // Split deque into 2 subdeque
    int mid = start + (end - start) / 2;
    MergeSort(vec, start, mid);
    MergeSort(vec, mid + 1, end);
    // Merge sorted arrays
    Merge(vec, start, mid, end);
  }
}

void PmergeMe::SortDeque(){
  if (this->deque_array_.empty() == true){ throw PmergeMe::Uninitialized_array(); }
  // ⏰ Start Sort Time
  struct timeval start, end;
  gettimeofday(&start, NULL);
  // Pair values (odd value stored alone with int max)
  std::deque< std::pair<int, int> > paired_deque;
  for (size_t i = 0; i < deque_array_.size(); i += 2) {
    if (deque_array_.size() % 2 != 0 && i >= deque_array_.size() - 2) {
      paired_deque.push_back(std::make_pair(std::numeric_limits<int>::max(), deque_array_[i]));
    } else {
      paired_deque.push_back(std::make_pair(deque_array_[i], deque_array_[i + 1]));
    }
  }

  // Sort each pair (ascending order)
  for (size_t i = 0; i < paired_deque.size(); ++i) {
    if (origin_array_.size() % 2 != 0 && i == paired_deque.size() - 1) {
      continue;
    } else if (paired_deque[i].second < paired_deque[i].first) {
      std::swap(paired_deque[i].first, paired_deque[i].second);
    }
  }

  // Recursively sort the paired_deque (in ascending order)
  MergeSort(paired_deque, 0, paired_deque.size() - 1);

  // Separate Main Chain (pair[0]) and Pending Chain (pair[1])
  std::deque<int> main_chain;
  std::deque<int> pending_chain;
  for (size_t i = 0; i < paired_deque.size(); ++i) {
    if (origin_array_.size() % 2 != 0 && i == paired_deque.size() - 1) {
      pending_chain.push_back(paired_deque[i].second);
    } else {
      main_chain.push_back(paired_deque[i].first);
      pending_chain.push_back(paired_deque[i].second);
    }
  }

  // Bin Insert sort with Jacobsthal numbers (to reduce amount of comparison
  // thanks to order of jacobsthal numbers)
  BinaryInsertSort(main_chain, pending_chain);

  // Save sorted array
  deque_array_ = main_chain;
  // ⏰ Stop time deque sort
  gettimeofday(&end, NULL);
  long seconds = end.tv_sec - start.tv_sec;
  long micros = (seconds * 1000000) + end.tv_usec - start.tv_usec;
  set_time_deque_sort(micros);
}

/* ================================ Exception =============================== */

const char* PmergeMe::Uninitialized_array::what() const throw(){
  return "Object Array to sort not initialized";
}

const char* PmergeMe::Unsorted::what() const throw(){
  return "Error in sort or Sort function not called";
}

/* ================================= Output ================================= */

std::ostream &operator<<(std::ostream &os, const PmergeMe &obj){
  int label_size = 8;
  os
    << MAGB << std::setw(label_size) << " Before " << RESET << " ";
  std::vector<int> temp_origin = obj.get_origin();
  std::vector<int>::const_iterator it;
  for(it = temp_origin.begin(); it != temp_origin.end(); it++) {
    os << *it << " ";
  }
  os << std::endl;
  os
    << GRNB << std::setw(label_size) << " After " << RESET << " ";
  std::vector<int> temp_after = obj.get_vector();
  std::vector<int>::const_iterator it_after;
  for(it_after = temp_after.begin(); it_after != temp_after.end(); it_after++) {
    os << *it_after << " ";
  }
  os << std::endl;
  os
    << BLUB << std::setw(label_size) << " Time " << RESET << " "
    << "Time to process a range of " << BBLU << temp_after.size() << RESET
    << " elements with " << BBLU << "std::[vector]" << RESET << " : "
    << BYEL << obj.get_vector_time() << RESET
    << " us";
  os << std::endl;
  os
    << BLUB << std::setw(label_size) << " Time " << RESET << " "
    << "Time to process a range of " << BBLU << temp_after.size() << RESET
    << " elements with " << BBLU << "std::[deque]" << RESET << " : "
    << BYEL << obj.get_deque_time() << RESET
    << " us";
  os << std::endl;
  return os;
}