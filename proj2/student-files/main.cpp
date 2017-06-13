#include <iostream>
#include <string>

#include "string_bst.hpp"
#include "max_heap.hpp"
#include "text_item.hpp"
#include "util.hpp"

using namespace std;

//--- PART 1A: Implementation and testing of heap insert
void heap_insert_tests(max_heap &hp) {
	text_item temp;
	std::string word = "item";
	int random_num;
	long int seed = long(time(0));    // seed for random number generator
	srand(seed);
	
	//--- Testing insert functionality
	std::cout << "*** TESTING INSERT ***" << std::endl;
	//--- This adds 5 items to the heap with random numbers
	//    and prints out the top, but it does not fully 
	//    test the correctness of the insert function.
	for (int i = 0 ; i < 5; i++) {
		random_num = rand() % 100;
		string text = word;
		text += std::to_string(i+1);
		std::cout << "adding " << text << ",  with number " << random_num << " to heap" << std::endl;
		hp.insert(text_item{text, random_num});	
		temp = hp.top();
		std::cout << "Top of heap is: " << temp << std::endl;		
	}
	for (int i = 0; i < 5; i++) {
	std::cout << "deleting " << hp.top().word << ", with number " << hp.top().freq << std::endl;
	hp.delete_max();
	}
	if (hp.empty()) {
		std::cout << "The heap is now empty!" << std::endl;
	}
	std::cout << "*Test Complete*" << std::endl;	
	
	//--- Specific insert functionality that should be tested:
	
	// insert without any swap_ups needed
		// <INSERT TEST(S) HERE>
	std::cout << "*** TESTING INSERT (NO SWAP_UPS) ***" << std::endl;
	int j = 6;
	for (int i = 5; i > 0; i--) {
		string text = word;
		text += std::to_string(j+1);
		j++;
		std::cout << "adding " << text << ", with number " << i << " to heap" << std::endl;
		hp.insert(text_item{text, i});
		temp = hp.top();
		std::cout << "Top of heap is: " << temp << std::endl;
	}
	for (int i = 0; i < 5; i++) {
	std::cout << "deleting " << hp.top().word << ", with number " << hp.top().freq << std::endl;
	hp.delete_max();
	}
	if (hp.empty()) {
		std::cout << "The heap is now empty!" << std::endl;
	}
	std::cout << "**Test Complete**" << std::endl;		
		
	// insert with a swap_up / multiple swap_ups
		// <INSERT TEST(S) HERE>
	std::cout << "*** TESTING INSERT (SWAP_UPS) ***" << std::endl;
	int k = 12;
	for (int i = 0; i < 8; i++) {
		string text = word;
		text += std::to_string(k+1);
		k++;
		std::cout << "adding " << text << ", with number " << i << " to heap" << std::endl;
		hp.insert(text_item{text, i});
		temp = hp.top();
		std::cout << "Top of heap is: " << temp << std::endl;
	}
	for (int i = 0; i < 8; i++) {
	std::cout << "deleting " << hp.top().word << ", with number " << hp.top().freq << std::endl;
	hp.delete_max();
	}
	if (hp.empty()) {
		std::cout << "The heap is now empty!" << std::endl;
	}
	std::cout << "***Test Complete***" << std::endl;		
}

//--- PART 1B: Implementation and testing of heap delete
void heap_delete_tests(max_heap &hp) {
	text_item temp;
	std::string word = "item";
	
	//--- Testing deleteMax functionality
	std::cout << "*** TESTING DELETEMAX ***" << std::endl;
	//--- This does not fully test delete_max functionality.
	if (hp.size() > 1) {
		temp = hp.delete_max();
		std::cout << "Item returned from heap delete: "<< temp << std::endl;
		temp = hp.top();
		std::cout << "Top of heap is now: " << temp << std::endl;	
	}
	
	//--- Specific insert functionality that should be tested:
	
	// remove_max works when swap_down with left child
	std::cout << "** TESTING REMOVE_MAX ON SWAP_DOWN WITH LEFT CHILD **" << std::endl;
	for (int i = 0; i < 2; i++) {
		string text = word;
		text += std::to_string(i+1);
		std::cout << "adding " << text << ", with number " << i << " to heap" << std::endl;
		hp.insert(text_item{text, i});
		temp = hp.top();
		std::cout << "Top of heap is: " << temp << std::endl;
	}
	std::cout << "deleting " << hp.top().word << ", with number " << hp.top().freq << std::endl;
	hp.delete_max();
	std::cout << "deleting " << hp.top().word << ", with number " << hp.top().freq << std::endl;
	hp.delete_max();
	if (hp.empty()) {
		std::cout << "The heap is now empty!" << std::endl;
	}
	std::cout << "*Test Complete*" << std::endl;
		
	// remove_max works when swap_down with right child
	std::cout << "** TESTING REMOVE_MAX ON SWAP_DOWN WITH RIGHT CHILD **" << std::endl;
	for (int i = 0; i < 3; i++) {
		string text = word;
		text += std::to_string(i+1);
		std::cout << "adding " << text << ", with number " << i << " to heap" << std::endl;
		hp.insert(text_item{text, i});
		temp = hp.top();
		std::cout << "Top of heap is: " << temp << std::endl;
	}
	std::cout << "deleting " << hp.top().word << ", with number " << hp.top().freq << std::endl;
	hp.delete_max();
	std::cout << "deleting " << hp.top().word << ", with number " << hp.top().freq << std::endl;
	hp.delete_max();
	std::cout << "deleting " << hp.top().word << ", with number " << hp.top().freq << std::endl;
	hp.delete_max();
	if (hp.empty()) {
		std::cout << "The heap is now empty!" << std::endl;
	}
	std::cout << "**Test Complete**" << std::endl;	
	
	// remove_max on an empty heap (should throw exception similar to top())
	std::cout << "** TESTING REMOVE_MAX ON EMPTY HEAP **" << std::endl;
	try {
		hp.delete_max();
	} catch(std::logic_error&) {
		std::cout << "Cannot delete, heap is empty!" << std::endl;
	}
	std::cout << "***Test Complete***" << std::endl;
		
}

//--- PART 2: Implementation and testing of BST word_frequency
void tree_tester(string_bst const &tree) {
	std::cout << std::endl << "BEGINNING TESTS FOR PART 2" << std::endl;
	
	//--- Testing word_frequency functionality
	//--- This does not fully test word_frequency functionality.
	if (tree.size() > 1) {
		string to_find = "difficult";
		int num_times = tree.word_frequency(to_find);
		std::cout << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << std::endl;
	}
	
	//--- Specific word_frequency functionality that should be tested:
	
	// can search through both left and right subtrees if not found at current node
	if (tree.size() > 1) { //
		int num_times = tree.word_frequency("ash");
		std::cout << "found: ash in the input file " << num_times << " time(s)." << std::endl;
	}
	
		
	// returns 0 if word is not found
	if (tree.size() > 1) {
		int num_times = tree.word_frequency("abcdefghj");
		std::cout << "found: abcdefghj in the input file " << num_times << " time(s)." << std::endl; 
	}		
}

//--- PART 3: Implementation and testing of word frequency analysis
void overall_most_freq(max_heap hp) {
	std::cout << "*** Top 5 most frequent words: ***" << std::endl;
	
	//--- Add your code to print out the 5 most frequent words below:
	if (hp.size() > 1) {
		if (hp.size() < 5) {
            int size = hp.size();
			for (int i = 0; i < size; i++) {
				std::cout << hp.top() << std::endl;
				hp.delete_max();
			}
		}
		else {
			for (int i = 0; i < 5; i++) {
				std::cout << hp.top() << std::endl;
				hp.delete_max();
			}
		}
	}

}

void at_least_length(max_heap hp, size_t num_letters) {
	cout << "*** Top 5 most frequent words with at least " 
		<< num_letters << " letters ***" << std::endl;
	max_heap* temp = new max_heap(hp.size());
	if (hp.size() > 1) {
		int size = hp.size();
		for (int i = 0; i < size; i++) {
			text_item top = hp.top();
			if (top.word.length() >= num_letters) {
				temp->insert(top);
			}
			hp.delete_max();
		}
	}
	if (temp->size() >= 1) {
		if (temp->size() < 5) {
            int size = temp->size();
			for (int i = 0; i < size; i++) {
				std::cout << temp->top() << std::endl;
				temp->delete_max();
			}
		}
		else {
			for (int i = 0; i < 5; i++) {
				std::cout << temp->top() << std::endl;
				temp->delete_max();
			}
		}
	}		
}

void starts_with(max_heap hp, char starts_with_letter) {
	cout << "*** Top 5 most frequent words that begin with " 
		<< starts_with_letter << " ***" << std::endl;
	max_heap* temp = new max_heap(hp.size());
	if (hp.size() > 1) {
		int size = hp.size();
		for (int i = 0; i < size; i++) {
			text_item top = hp.top();
			if (top.word[0] == starts_with_letter) {
				temp->insert(top);
			}
			hp.delete_max();
		}
	}
	if (temp->size() >= 1) {
		if (temp->size() < 5) {
            int size = temp->size();
			for (int i = 0; i < size; i++) {
				std::cout << temp->top() << std::endl;
				temp->delete_max();
			}
		}
		else {
			for (int i = 0; i < 5; i++) {
				std::cout << temp->top() << std::endl;
				temp->delete_max();
			}
		}
	}	
}

void heap_tester() {	
	text_item temp;
	int heap_size = 10; //feel free to create heaps of other sizes when testing
	//cout << "How many items should be added to heap? ";
	//cin >> heap_size;
	max_heap hp(heap_size);
	std::cout << "Created heap of size " << heap_size << std::endl;
		
	//--- Testing heap size and top
	std::cout << "Current number of items in heap is: " << hp.size() << std::endl;
	try {
		temp = hp.top(); //should throw and exception without items in heap
		std::cout << "Top of heap is: " << temp << std::endl;	
	} catch (std::logic_error e) {
		std::cout << e.what() << std::endl;
	}
	// PART 1A:
	std::cout << std::endl << "BEGINNING TESTS FOR PART 1A" << std::endl;
	heap_insert_tests(hp);
	// PART 1B:
	std::cout << std::endl << "BEGINNING TESTS FOR PART 1B" << std::endl;
	heap_delete_tests(hp);
}

void text_analysis_tester(string_bst &tree) {
	std::cout << std::endl << "BEGINNING TESTS FOR PART 3" << std::endl;
	overall_most_freq(copy_to_heap(tree));
	std::cout << std::endl;
	at_least_length(copy_to_heap(tree), 2); // change the 8 to test other string-lengths
	std::cout << std::endl;
	starts_with(copy_to_heap(tree), 'g'); // change the 'c' to test words that starts_with_letter
											// with different characters
}

int main(int argc, char* argv[]) {
	
	//--- Part 1: max_heap implementation
	heap_tester(); 
	
	//--- Part 2: string_bst implementation
	string_bst tree;
	load_bst("sample2.txt", tree); // create a bst from an input file.
	tree_tester(tree);			//sample2.txt contains a much bigger file
	
	//--- Part 3: word frequency analysis of text files
	text_analysis_tester(tree);

}
