#include "String.h"
#include <iostream>
#include <string>


int main()
{
	// ------------------------------------------------------------
	// Basic string information
	// ------------------------------------------------------------

	String text("Hello World");

	std::cout << "=== String Information ===\n";
	std::cout << "Content:    " << text.data() << '\n';
	std::cout << "Size:       " << text.size() << '\n';
	std::cout << "Length:     " << text.length() << '\n';
	std::cout << "Capacity:   " << text.capacity() << '\n';
	std::cout << "Is empty:   " << std::boolalpha << text.is_empty() << '\n';


	std::cout << "\n=======================================\n\n";


	// ------------------------------------------------------------
	// Element access
	// ------------------------------------------------------------

	String text2("Hello");

	std::cout << "=== Element Access ===\n";
	std::cout << "text2 Content:              " << text2.data() << '\n';
	std::cout << "text2[1]:                   " << text2[1] << '\n';
	std::cout << "text2.at(1):                " << text2.at(1) << '\n';

	text2[0] = 'J';

	std::cout << "text2[0] = 'J':             " << text2.data() << '\n';


	std::cout << "\n=======================================\n\n";


	// ------------------------------------------------------------
	// Bounds checking
	// ------------------------------------------------------------

	std::cout << "=== Bounds Checking ===\n";

	std::cout << "Trying to access text2.at(100)...\n";

	try {
		text2.at(100);
	}
	catch (const std::out_of_range& error) {
		std::cout << "Exception: " << error.what() << '\n';
	}


	// ------------------------------------------------------------
	// Assignment
	// ------------------------------------------------------------

	std::cout << "\n=== Assignment ===\n";

	String text3("Initial");

	std::cout << "text3 Content:               "
		<< text3.data() << '\n';

	text3.assign("Hello");

	std::cout << "text3.assign(\"Hello\"):       "
		<< text3.data() << '\n';

	text3.assign('X');

	std::cout << "text3.assign('X'):           "
		<< text3.data() << '\n';

	String text4("Source");

	std::cout << "text4 Content:               "
		<< text4.data() << '\n';

	text3.assign(text4);

	std::cout << "text3.assign(text4):         "
		<< text3.data() << '\n';

	text3 = "World";

	std::cout << "text3 = \"World\":             "
		<< text3.data() << '\n';

	text3 = "Y";

	std::cout << "text3 = \"Y\":                 "
		<< text3.data() << '\n';

	text3 = text4;

	std::cout << "text3 = text4:               "
		<< text3.data() << '\n';


	// ------------------------------------------------------------
	// Append
	// ------------------------------------------------------------

	std::cout << "\n=======================================\n\n";
	std::cout << "=== Append ===\n";

	String text5("Hello");

	std::cout << "text5 Content:                    "
		<< text5.data() << '\n';

	text5.append(" World");
	std::cout << "text5.append(\" World\"):           "
		<< text5.data() << '\n';

	text5.append('!');
	std::cout << "text5.append('!'):                "
		<< text5.data() << '\n';

	String text6(" Again");
	text5.append(text6);
	std::cout << "text5.append(text6):              "
		<< text5.data() << '\n';


	std::cout << "\n--- Append with Reallocation ---\n";

	String text7("Hello");

	std::cout << "text7 Content:                    "
		<< text7.data() << '\n';

	std::cout << "text7 Capacity:                   "
		<< text7.capacity() << '\n';

	text7.append(" this is a longer string");

	std::cout << "text7.append(...):                "
		<< text7.data() << '\n';

	std::cout << "text7 Capacity:                   "
		<< text7.capacity() << '\n';

	text7.append(" and even a longer one");

	std::cout << "text7.append(...):                "
		<< text7.data() << '\n';

	std::cout << "text7 Capacity:                   "
		<< text7.capacity() << '\n';


	std::cout << "\n--- Self Append ---\n";

	String text8("Hello");

	std::cout << "text8 Before:                     "
		<< text8.data() << '\n';

	text8.append(text8);

	std::cout << "text8.append(text8):              "
		<< text8.data() << '\n';


	// ------------------------------------------------------------
	// Insert
	// ------------------------------------------------------------

	std::cout << "\n=======================================\n\n";
	std::cout << "=== Insert ===\n";

	String text9("Hello World");

	std::cout << "text9 Content:                    "
		<< text9.data() << '\n';

	text9.insert(5, " beautiful");
	std::cout << "text9.insert(5, \" beautiful\"):    "
		<< text9.data() << '\n';

	text9.insert(0, "Say ");
	std::cout << "text9.insert(0, \"Say \"):          "
		<< text9.data() << '\n';

	text9.insert(text9.size(), '!');
	std::cout << "text9.insert(end, '!'):           "
		<< text9.data() << '\n';


	// ------------------------------------------------------------
	// Erase
	// ------------------------------------------------------------

	std::cout << "\n=======================================\n\n";
	std::cout << "=== Erase ===\n";

	String text10("Hello beautiful World!");

	std::cout << "text10 Content:                   "
		<< text10.data() << '\n';

	text10.erase(5, 10);
	std::cout << "text10.erase(5, 10):              "
		<< text10.data() << '\n';

	text10.erase(0, 6);
	std::cout << "text10.erase(0, 6):               "
		<< text10.data() << '\n';

	text10.erase(text10.size() - 1, 1);
	std::cout << "text10.erase(last char):          "
		<< text10.data() << '\n';


	// ------------------------------------------------------------
	// Find / Substring
	// ------------------------------------------------------------

	std::cout << "\n=======================================\n\n";
	std::cout << "=== Find ===\n";

	String text11("Hello beautiful World");

	std::cout << "text11 Content:                   "
		<< text11.data() << '\n';

	std::cout << "text11.find(\"beautiful\"):         "
		<< text11.find("beautiful") << '\n';

	std::cout << "text11.find(\"World\"):             "
		<< text11.find("World") << '\n';

	std::cout << "text11.find(\"xyz\"):               "
		<< text11.find("xyz") << '\n';


	std::cout << "\n=== Substring ===\n";

	String text12("Hello World");

	std::cout << "text12 Content:                   "
		<< text12.data() << '\n';

	String text13 = text12.substr(0, 4);

	std::cout << "text13 = text12.substr(0, 4):     "
		<< text13.data() << '\n';

	String text14 = text12.substr(6, 10);

	std::cout << "text14 = text12.substr(6, 10):    "
		<< text14.data() << '\n';


	// ------------------------------------------------------------
	// Comparison
	// ------------------------------------------------------------

	std::cout << "\n=======================================\n\n";
	std::cout << "=== Comparison ===\n";

	String first("Hello");
	String second("Hello");
	String third("World");

	std::cout << "first:                     "
		<< first.data() << '\n';

	std::cout << "second:                    "
		<< second.data() << '\n';

	std::cout << "third:                     "
		<< third.data() << '\n';

	std::cout << "\n--- compare() ---\n";

	std::cout << "first.compare(second):     "
		<< first.compare(second) << '\n';

	std::cout << "first.compare(third):      "
		<< first.compare(third) << '\n';

	std::cout << "third.compare(first):      "
		<< third.compare(first) << '\n';

	std::cout << "\n--- compare_equal() ---\n";

	std::cout << "first == second:           "
		<< first.compare_equal(second) << '\n';

	std::cout << "first == third:            "
		<< first.compare_equal(third) << '\n';


	std::cout << "\n--- Comparison Operators ---\n";

	std::cout << "first == second:           "
		<< (first == second) << '\n';

	std::cout << "first != third:            "
		<< (first != third) << '\n';

	std::cout << "first < third:             "
		<< (first < third) << '\n';

	std::cout << "third > first:             "
		<< (third > first) << '\n';

	std::cout << "first <= second:           "
		<< (first <= second) << '\n';

	std::cout << "third >= first:            "
		<< (third >= first) << '\n';

	std::cout << "first > third:             "
		<< (first > third) << '\n';


	std::cout << "\n--- Comparison with C-Strings ---\n";

	std::cout << "first == \"Hello\":          "
		<< (first == "Hello") << '\n';

	std::cout << "first != \"World\":          "
		<< (first != "World") << '\n';

	std::cout << "first < \"World\":           "
		<< (first < "World") << '\n';


	// ------------------------------------------------------------
	// Operators
	// ------------------------------------------------------------

	std::cout << "\n=======================================\n\n";
	std::cout << "=== Operators ===\n";

	String left("Hello");
	String right(" World");

	std::cout << "left:                              "
		<< left.data() << '\n';

	std::cout << "right:                            "
		<< right.data() << '\n';

	std::cout << "\n--- operator+ ---\n";

	String result1 = left + right;

	std::cout << "left + right:                      "
		<< result1.data() << '\n';

	String result2 = left + " World";

	std::cout << "left + \" World\":                   "
		<< result2.data() << '\n';

	String result3 = left + '!';

	std::cout << "left + '!':                        "
		<< result3.data() << '\n';


	std::cout << "\n--- operator+= ---\n";

	String text15("Hello");

	std::cout << "text15 Content:                    "
		<< text15.data() << '\n';

	text15 += " World";

	std::cout << "text15 += \" World\":                "
		<< text15.data() << '\n';

	text15 += '!';

	std::cout << "text15 += '!':                     "
		<< text15.data() << '\n';

	String text16(" Again");

	text15 += text16;

	std::cout << "text15 += text16:                  "
		<< text15.data() << '\n';


	std::cout << "\n--- Symmetric Operators ---\n";

	String text17("World");

	String result4 = "Hello " + text17;

	std::cout << "\"Hello \" + text17:                 "
		<< result4.data() << '\n';

	String result5 = '>' + text17;

	std::cout << "'>' + text17:                      "
		<< result5.data() << '\n';


	std::cout << "\n--- operator[] ---\n";

	String text18("Hello");

	std::cout << "text18 Content:                    "
		<< text18.data() << '\n';

	std::cout << "text18[0]:                         "
		<< text18[0] << '\n';

	text18[0] = 'J';

	std::cout << "text18[0] = 'J':                   "
		<< text18.data() << '\n';


	// ------------------------------------------------------------
	// Capacity
	// ------------------------------------------------------------

	std::cout << "\n=======================================\n\n";
	std::cout << "=== Capacity ===\n";

	String text19("Hello");

	std::cout << "text19 Content:                   "
		<< text19.data() << '\n';

	std::cout << "text19 Size:                      "
		<< text19.size() << '\n';

	std::cout << "text19 Capacity:                  "
		<< text19.capacity() << '\n';


	std::cout << "\n--- reserve() ---\n";

	text19.reserve(50);

	std::cout << "text19.reserve(50):\n";

	std::cout << "text19 Size:                      "
		<< text19.size() << '\n';

	std::cout << "text19 Capacity:                  "
		<< text19.capacity() << '\n';

	std::cout << "text19 Content:                   "
		<< text19.data() << '\n';


	std::cout << "\n--- shrink_to_fit() ---\n";

	text19.shrink_to_fit();

	std::cout << "text19.shrink_to_fit():\n";

	std::cout << "text19 Size:                      "
		<< text19.size() << '\n';

	std::cout << "text19 Capacity:                  "
		<< text19.capacity() << '\n';

	std::cout << "text19 Content:                   "
		<< text19.data() << '\n';


	// ------------------------------------------------------------
	// Copy / Move
	// ------------------------------------------------------------

	std::cout << "\n=======================================\n\n";
	std::cout << "=== Copy / Move ===\n";

	String original("Hello World");

	std::cout << "original:                  "
		<< original.data() << '\n';


	// ------------------------------------------------------------
	// Copy Constructor
	// ------------------------------------------------------------

	std::cout << "\n--- Copy Constructor ---\n";

	String copied(original);

	std::cout << "original:                  "
		<< original.data() << '\n';

	std::cout << "copied(original):          "
		<< copied.data() << '\n';

	copied[0] = 'J';

	std::cout << "copied[0] = 'J':\n";
	std::cout << "original:                  "
		<< original.data() << '\n';

	std::cout << "copied:                    "
		<< copied.data() << '\n';


	// ------------------------------------------------------------
	// Copy Assignment
	// ------------------------------------------------------------

	std::cout << "\n--- Copy Assignment ---\n";

	String assigned("Initial");

	std::cout << "assigned:                  "
		<< assigned.data() << '\n';

	assigned = original;

	std::cout << "assigned = original:\n";
	std::cout << "original:                  "
		<< original.data() << '\n';

	std::cout << "assigned:                  "
		<< assigned.data() << '\n';

	assigned[0] = 'X';

	std::cout << "assigned[0] = 'X':\n";
	std::cout << "original:                  "
		<< original.data() << '\n';

	std::cout << "assigned:                  "
		<< assigned.data() << '\n';


	// ------------------------------------------------------------
	// Move Constructor
	// ------------------------------------------------------------

	std::cout << "\n--- Move Constructor ---\n";

	String move_source("Move me");

	std::cout << "move_source before move:   "
		<< move_source.data() << '\n';

	String moved(std::move(move_source));

	std::cout << "moved(std::move(source)):  "
		<< moved.data() << '\n';

	std::cout << "move_source after move:    ";

	if (move_source.data() == nullptr) {
		std::cout << "nullptr\n";
	}
	else {
		std::cout << move_source.data() << '\n';
	}


	// ------------------------------------------------------------
	// Move Assignment
	// ------------------------------------------------------------

	std::cout << "\n--- Move Assignment ---\n";

	String move_source2("Move assignment");
	String move_target("Initial");

	std::cout << "move_source2:              "
		<< move_source2.data() << '\n';

	std::cout << "move_target:               "
		<< move_target.data() << '\n';

	move_target = std::move(move_source2);

	std::cout << "move_target = "
		<< "std::move(move_source2):\n";

	std::cout << "move_target:               "
		<< move_target.data() << '\n';

	std::cout << "move_source2 after move:   ";

	if (move_source2.data() == nullptr) {
		std::cout << "nullptr\n";
	}
	else {
		std::cout << move_source2.data() << '\n';
	}


	// ------------------------------------------------------------
	// Iterators
	// ------------------------------------------------------------

	std::cout << "\n=======================================\n\n";
	std::cout << "=== Iterators ===\n";

	String text20("Hello");

	std::cout << "text20 Content:                    "
		<< text20.data() << '\n';

	std::cout << "Characters:                        ";

	for (const char* iterator = text20.begin();
		iterator != text20.end();
		++iterator) {
		std::cout << *iterator;
	}

	std::cout << '\n';


	// ------------------------------------------------------------
	// Mutable Iterators
	// ------------------------------------------------------------

	std::cout << "\n--- Mutable Iterators ---\n";

	String text21("Hello");

	std::cout << "text21 Before:                     "
		<< text21.data() << '\n';

	for (char* iterator = text21.begin();
		iterator != text21.end();
		++iterator) {
		if (*iterator == 'e') {
			*iterator = 'a';
		}
	}

	std::cout << "text21 After modification:         "
		<< text21.data() << '\n';


	// ------------------------------------------------------------
	// Clear / Empty
	// ------------------------------------------------------------

	std::cout << "\n=======================================\n\n";
	std::cout << "=== Clear / Empty ===\n";

	String text22("Hello World");

	std::cout << "text22 Content:                   "
		<< text22.data() << '\n';

	std::cout << "text22 Is empty:                  "
		<< text22.is_empty() << '\n';

	text22.clear();

	std::cout << "text22.clear():\n";

	std::cout << "text22 Content:                   "
		<< text22.data() << '\n';

	std::cout << "text22 Size:                      "
		<< text22.size() << '\n';

	std::cout << "text22 Capacity:                  "
		<< text22.capacity() << '\n';

	std::cout << "text22 Is empty:                  "
		<< text22.is_empty() << '\n';


	// ------------------------------------------------------------
	// Edge Cases / Memory & Aliasing
	// ------------------------------------------------------------

	std::cout << "\n=======================================\n\n";
	std::cout << "=== Edge Cases / Memory & Aliasing ===\n";


	std::cout << "\n--- Self Append ---\n";

	String text23("Hello");

	std::cout << "text23 Before:                     "
		<< text23.data() << '\n';

	text23.append(text23);

	std::cout << "text23.append(text23):             "
		<< text23.data() << '\n';


	std::cout << "\n--- Insert with Aliased Data ---\n";

	String text24("Hello World");

	std::cout << "text24 Before:                     "
		<< text24.data() << '\n';

	text24.insert(5, text24.data());

	std::cout << "text24.insert(5, text24.data()):   "
		<< text24.data() << '\n';


	std::cout << "\n--- Insert with Internal Pointer ---\n";

	String text25("Hello World");

	std::cout << "text25 Before:                     "
		<< text25.data() << '\n';

	text25.insert(0, text25.data() + 6);

	std::cout << "text25.insert(0, data() + 6):      "
		<< text25.data() << '\n';


	std::cout << "\n--- Self Assignment ---\n";

	String text26("Hello World");

	std::cout << "text26 Before:                     "
		<< text26.data() << '\n';

	text26 = text26;

	std::cout << "text26 = text26:                   "
		<< text26.data() << '\n';


	std::cout << "\n--- Empty String ---\n";

	String empty_string;

	std::cout << "empty_string Content:              "
		<< empty_string.data() << '\n';

	std::cout << "empty_string Size:                 "
		<< empty_string.size() << '\n';

	std::cout << "empty_string Capacity:             "
		<< empty_string.capacity() << '\n';

	std::cout << "empty_string Is empty:             "
		<< empty_string.is_empty() << '\n';

	empty_string.append("Hello");

	std::cout << "empty_string.append(\"Hello\"):      "
		<< empty_string.data() << '\n';
}
