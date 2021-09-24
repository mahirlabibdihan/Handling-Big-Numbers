# Handling-Big-Numbers-CPP

A C++ code to handle big decimal  numbers like Java BigDecimal Class. More time consuming than BigDecimal but better functionality and Accuracy.The idea behind the working of this program is that using the traditional method for adding,subdtracting,multiplying numbers, the same method we used in primary classes. And the number is so large that it has been stored in string in the form of separate digits.It can calculate until the total digit of the result is <= string::max_size()

Created a wrapper class String over std::string with extra methods. And took an instance of String in BigDecimal Class.