#include "String.h"
class BigDecimal: public String {
public:
	BigDecimal(): String(){}
	unsigned long long toInt();
	void trim();
	int compareTo(BigDecimal);
};
