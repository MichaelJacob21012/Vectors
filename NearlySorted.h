#ifndef NEARLYSORTED_H
#define NEARLYSORTED_H


#include <vector>
using std::vector;

/** @brief Class that describes how to sort a nearly-sorted vector */
class HowToSort {
protected:

	/** @brief The index of the first element to use */
	int firstElement;

	/** @brief The index of the second element to use */
	int secondElement;

	/** @brief If true, firstElement and secondElement should be swapped; if false, the range of elements should be reversed */
	bool swapThem;

public:

	/** @brief Default constructor.
	 *
	 * This assumes that we can't sort the vector by swapping/reversing a range -- it sets both elements
	 * to have an index -1.
	 */
	HowToSort()
: firstElement(-1),
  secondElement(-1),
  swapThem(false) {
	}

	/** @brief The actual constructor: use this to define how to sort a nearly-sorted vector
	 *
	 * @param firstElementIn   The first element to use
	 * @param secondElementIn  The second element to use
	 * @param swapThemIn       If true, swap firstElementIn and secondElementIn; if false, reverse the range of elements
	 */
	HowToSort(const int firstElementIn, const int secondElementIn,
			const bool swapThemIn)
	: firstElement(firstElementIn),
	  secondElement(secondElementIn),
	  swapThem(swapThemIn) {
	}

	/** @brief Returns false if no way to sort the vector could be found (i.e. if firstElement == -1) */
	bool canBeMadeSorted() const {
		return (firstElement != -1);
	}

	/** @brief Accessor function -- get the first element to use */
	int getFirstElement() const {
		return firstElement;
	}

	/** @brief Accessor function -- get the second element to use */
	int getSecondElement() const {
		return secondElement;
	}

	/** @brief If true, the element indices denote a swap.  If false, they denote a range reversal. */
	bool isASwap() const {
		return swapThem;
	}

};

// TODO your code goes here:
bool isSorted(vector<int> numbers) {
	for (int i = 0; i < numbers.size() - 1; i ++){
		if (numbers[i] > numbers[i+1]){
			return false;
		}
	}
	return true;
}
HowToSort swap(vector<int> numbers){
	int count = 0;
	int firstSwap = 0;
	int secondSwap = 0;
	for (int i = 0; i < numbers.size() - 1; i ++){
		if (numbers [i] > numbers [i + 1]){
			count++;
		}
	}
	if (count != 2){
		return HowToSort();
	}
	for (int i = 0; i < numbers.size() - 1; i ++){
		if (numbers [i] > numbers [i + 1]){
			firstSwap = i;
			break;
		}
	}
	for (int i = firstSwap + 1; i < numbers.size() - 1; i ++){
		if (numbers [i] > numbers [i + 1]){
			secondSwap = i + 1;
			break;
		}
	}
	if (numbers[firstSwap] < numbers[secondSwap]){
		return HowToSort();
	}
	return HowToSort(firstSwap,secondSwap,true);
}
bool canReverse(vector<int> numbers){
	int started = false;
	int count = 0;
	for (int i = 0; i < numbers.size() - 1; i ++){
		if (started == true){
			if (numbers [i] < numbers [i +1]){
				started = false;
			}
		}
		else if (numbers [i] > numbers [i + 1]){
			started = true;
			count ++;
			if (count > 1){
				return false;
			}
		}
	}
	if (count == 1){
		return true;
	}
	return false;
}
HowToSort reverse(vector<int> numbers){
	int start = 0;
	for (int i = 0; i < numbers.size() - 1; i++){
		if (numbers [i] > numbers [i +1]){
			start = i;
			break;
		}
	}
	int end = start;
	while (!(numbers [end] < numbers [end + 1])){
		if (end == numbers.size()-1){
			break;
		}
		end++;
	}
	return HowToSort(start,end,false);

}
HowToSort nearlySorted(vector<int> numbers){
	if (isSorted(numbers)){
		return HowToSort(0,0,true);
	}
	HowToSort answer = HowToSort();
	answer = swap(numbers);
	if (answer.getFirstElement() == -1 && canReverse(numbers)){
		answer = reverse(numbers);
	}
	return answer;
}






// Don't write any code below this line

#endif
