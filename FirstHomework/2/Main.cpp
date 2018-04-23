#include <iostream>
#include "BrowserHistory.h"

int main()
{
	HistoryEntry entry1(4, "https://learn.fmi.uni-sofia.bg/login/index.php");
	HistoryEntry entry2(3, "https://www.google.bg/");
	HistoryEntry entry3(6, "https://www.fmi.uni-sofia.bg/");

	BrowserHistory ivanchoHistory(10);
	ivanchoHistory.addHistoryEntry(entry1);
	ivanchoHistory.addHistoryEntry(entry2);
	ivanchoHistory.addHistoryEntry(entry3);
	ivanchoHistory.addHistoryEntry(HistoryEntry(3, "https://www.tochka.bg/"));
	ivanchoHistory.addHistoryEntry(HistoryEntry(3, "https://www.github.com/"));

	ivanchoHistory.printOnConsole();
	std::cout << ivanchoHistory.getMostPopularMonth() << "\n";

	BrowserHistory mariaHistory(10);
	mariaHistory.addHistoryEntry(HistoryEntry(1, "https://abv.bg"));
	mariaHistory.addHistoryEntry(HistoryEntry(1, "https://en.wikipedia.org/wiki/Reverse_Polish_notation"));
	mariaHistory.addHistoryEntry(HistoryEntry(3, "https://gosho.peshev.it"));
	mariaHistory.printOnConsole();

	BrowserHistory result = ivanchoHistory + mariaHistory;
	result.printOnConsole();

	int mostPopular = result.getMostPopularMonth();
	std::cout << "Most popular month: " << mostPopular << "\n";
	std::cout << "Sites count in most popular month: " << result.getSitesCountByMonth(mostPopular) << "\n";

	// result.readHistoryEntry();
	// result.printOnConsole();

	return 0;
}