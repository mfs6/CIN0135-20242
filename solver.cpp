/* #include <iostream>

#include "list.hpp"

using namespace std;

int main()
{
	int nCases;
	cin >> nCases;
	for (int caseNo = 0; caseNo < nCases; caseNo++)
	{
		// ADD CODE HERE
		string op;
		string i;
		string v;
		string j; // Para MERGE

		while (true)
		{
			cin >> op;
			if (op == "END")
				break;

			if (op == "ADD")
			{
				cin >> i >> v;
			}
			else if (op == "DEL")
			{
				cin >> i;
			}
			else if (op == "SPL")
			{
				cin >> i;
			}
			else if (op == "MER")
			{
				cin >> i >> j;
			}
			else if (op == "TRA")
			{
				cin >> i;
			}
		}
	}
} */

#include <iostream>
#include <vector>
#include <string>
#include "list.hpp"

using namespace std;

int main()
{
	int nCases;
	cin >> nCases;
	for (int caseNo = 0; caseNo < nCases; caseNo++)
	{
		vector<SQ<int> *> sqs;
		sqs.push_back(new SQ<int>(QUEUE)); // Inicialmente uma fila vazia na posição 0

		string op;
		while (true)
		{
			cin >> op;
			if (op == "END")
				break;

			int i, j, v;
			if (op == "ADD")
			{
				cin >> i >> v;
				sqs[i]->push(v);
			}
			else if (op == "DEL")
			{
				cin >> i;
				if (sqs[i]->size() > 0)
					sqs[i]->pop();
			}
			else if (op == "SPL")
			{
				cin >> i;
				SQ<int> *newSQ = sqs[i]->split();
				sqs.insert(sqs.begin() + i + 1, newSQ);
			}
			else if (op == "MER")
			{
				cin >> i >> j;
				sqs[i]->merge(sqs[j]);
				delete sqs[j];
				sqs.erase(sqs.begin() + j);
			}
			else if (op == "TRA")
			{
				cin >> i;
				sqs[i]->transform();
			}
		}

		cout << "caso " << caseNo << ":";
		for (auto sq : sqs)
		{
			if (sq->size() > 0)
				cout << " " << sq->peek();
			else
				cout << " ?";
		}
		cout << endl;

		// Limpar a memória
		for (auto sq : sqs)
		{
			delete sq;
		}
	}
	return 0;
}