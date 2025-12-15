#include "PmergeMe.hpp"

std::string generateRand(int n) {
	std::string result;
	int seq[n];
	srand(time(0));
	for (int i = 0; i < n; i++) {
		seq[i] = rand() % 10000;
		// Ensure uniqueness
		for (int j = 0; j < i; j++) {
			if (seq[i] == seq[j]) {
				seq[i] = rand() % 10000;
				j = -1; // Restart checking
			}
		}
		result += numToStr(seq[i]);
		if (i != n - 1)
			result += " ";
	}
	return result;
}

int main() {
	std::cout << "PmergeMe tester" << std::endl;
	std::cout << "Testing 1: empty input..." << std::endl;
	try {
		listFunctions::algoRun("");
		vectorFunctions::algoRun("");
	} catch (const std::exception &e) {
		std::cerr << "Caught exception as expected: " << e.what() << std::endl;
	}

	std::cout << "Testing 2: single element input..." << std::endl;
	try {
		listFunctions::algoRun("42");
		vectorFunctions::algoRun("42");
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "Testing 3: Negative input..." << std::endl;
	try {
		listFunctions::algoRun("3 -1 4");
		vectorFunctions::algoRun("3 -1 4");
	} catch (const std::exception &e) {
		std::cerr << "Caught exception as expected: " << e.what() << std::endl;
	}

	std::cout << "Testing 4: Correct ordered input..." << std::endl;
	try {
		listFunctions::algoRun("1 2 3 4 5");
		vectorFunctions::algoRun("1 2 3 4 5");
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "Testing 5: Correct reverse ordered input..." << std::endl;
	try {
		std::string testStr = "10 9 8 7 6 5 4 3 2 1";
		std::list<int> ltocmp = listFunctions::algoRun(testStr);
		std::vector<int> vtocmp = vectorFunctions::algoRun(testStr);
		std::list<int> reflst(ltocmp);
		std::vector<int> refvec(vtocmp);
		reflst.sort();
		std::sort(refvec.begin(), refvec.end());
		if (std::equal(ltocmp.begin(), ltocmp.end(), reflst.begin()) && std::equal(vtocmp.begin(), vtocmp.end(), refvec.begin()))
			std::cout << "✅ SUCCESS" << std::endl;
		else
			std::cout << "❌ FAILURE" << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "Testing 6: Input with duplicates..." << std::endl;
	try {
		listFunctions::algoRun("1 2 3 2 4 5");
		vectorFunctions::algoRun("1 2 3 2 4 5");
	} catch (const std::exception &e) {
		std::cout << "✅ SUCCESS" << std::endl;
		std::cerr << "Caught exception as expected: " << e.what() << std::endl;
	}

	std::cout << "Testing 7: Input with non-integer values..." << std::endl;
	try {
		listFunctions::algoRun("1 2 three 4 5");
		vectorFunctions::algoRun("1 2 three 4 5");
	} catch (const std::exception &e) {
		std::cout << "✅ SUCCESS" << std::endl;
		std::cerr << "Caught exception as expected: " << e.what() << std::endl;
	}

	std::cout << "Testing 8: Small random input of 10 elements..." << std::endl;
	try {
		std::string smallInput = generateRand(10);

		std::list<int> ltocmp = listFunctions::algoRun(smallInput);
		std::vector<int> vtocmp = vectorFunctions::algoRun(smallInput);
		std::list<int> reflst(ltocmp);
		std::vector<int> refvec(vtocmp);
		reflst.sort();
		std::sort(refvec.begin(), refvec.end());
		if (std::equal(ltocmp.begin(), ltocmp.end(), reflst.begin()) && std::equal(vtocmp.begin(), vtocmp.end(), refvec.begin()))
			std::cout << "✅ SUCCESS" << std::endl;
		else
			std::cout << "❌ FAILURE" << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "Testing 9: Input of 100 random elements..." << std::endl;
	try {
		std::string mediumInput = generateRand(100);
		std::list<int> ltocmp = listFunctions::algoRun(mediumInput);
		std::vector<int> vtocmp = vectorFunctions::algoRun(mediumInput);
		std::list<int> reflst(ltocmp);
		std::vector<int> refvec(vtocmp);
		reflst.sort();
		std::sort(refvec.begin(), refvec.end());
		if (std::equal(ltocmp.begin(), ltocmp.end(), reflst.begin()) && std::equal(vtocmp.begin(), vtocmp.end(), refvec.begin()))
			std::cout << "✅ SUCCESS" << std::endl;
		else
			std::cout << "❌ FAILURE" << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "Testing 10: Input of 1000 random elements..." << std::endl;
	try {
		std::string largeInput = generateRand(1000);
		std::list<int> ltocmp = listFunctions::algoRun(largeInput);
		std::vector<int> vtocmp = vectorFunctions::algoRun(largeInput);
		std::list<int> reflst(ltocmp);
		std::vector<int> refvec(vtocmp);
		reflst.sort();
		std::sort(refvec.begin(), refvec.end());
		if (std::equal(ltocmp.begin(), ltocmp.end(), reflst.begin()) && std::equal(vtocmp.begin(), vtocmp.end(), refvec.begin()))
			std::cout << "✅ SUCCESS" << std::endl;
		else
			std::cout << "❌ FAILURE" << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "Testing 11: Input of 3000 random elements..." << std::endl;
	try {
		std::string largeInput = generateRand(3000);

		std::list<int> ltocmp = listFunctions::algoRun(largeInput);
		std::vector<int> vtocmp = vectorFunctions::algoRun(largeInput);
		std::list<int> reflst(ltocmp);
		std::vector<int> refvec(vtocmp);
		reflst.sort();
		std::sort(refvec.begin(), refvec.end());
		if (std::equal(ltocmp.begin(), ltocmp.end(), reflst.begin()) && std::equal(vtocmp.begin(), vtocmp.end(), refvec.begin()))
			std::cout << "✅ SUCCESS" << std::endl;
		else
			std::cout << "❌ FAILURE" << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
