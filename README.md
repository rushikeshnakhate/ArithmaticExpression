# ArithmaticExpression

1. Problem Statement

![image](https://user-images.githubusercontent.com/14144934/133921048-8ae17d99-9bf9-4a00-8cf1-15a6040fd576.png)


Development Process :

1. Devided Problem into bunch of small Tasks All can be found here https://github.com/rushikeshnakhate/ArithmaticExpression/issues?q=
2. TDD Approch - Added test for each path and then Added implelemntation .
3. Branchs information Please find the list of branches , PR raise during the development process -https://github.com/rushikeshnakhate/ArithmaticExpression/branches
Please follow below steps to run the application

4. git clone https://github.com/rushikeshnakhate/ArithmaticExpression.git

```
Cloning into 'ArithmaticExpression'...
remote: Enumerating objects: 375, done.
remote: Counting objects: 100% (375/375), done.
remote: Compressing objects: 100% (266/266), done.
remote: Total 375 (delta 98), reused 352 (delta 90), pack-reused 0
Receiving objects: 100% (375/375), 1007.77 KiB | 965.00 KiB/s, done.
Resolving deltas: 100% (98/98), done.
```


5.Compilation 
cd ArithmaticExpression ; /usr/local/bin/cmake CMakeLists.txt
```
-- The C compiler identification is GNU 7.5.0
-- The CXX compiler identification is GNU 7.5.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found Python: /usr/bin/python3.6 (found version "3.6.9") found components:  Interpreter
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Failed
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - found
-- Found Threads: TRUE
-- Configuring done
-- Generating done
-- Build files have been written to: /home/rushi/ArithmaticExpression
```


6. Make
make
```
Scanning dependencies of target gtest
[  3%] Building CXX object src/test/libs/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[  7%] Linking CXX static library ../../../../lib/libgtest.a
[  7%] Built target gtest
Scanning dependencies of target gtest_main
[ 11%] Building CXX object src/test/libs/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 14%] Linking CXX static library ../../../../lib/libgtest_main.a
[ 14%] Built target gtest_main
Scanning dependencies of target ArithmeticExpressionTest
[ 18%] Building CXX object src/test/CMakeFiles/ArithmeticExpressionTest.dir/__/main/database/TokenDatabase.cpp.o
[ 22%] Building CXX object src/test/CMakeFiles/ArithmeticExpressionTest.dir/__/main/engine/ShuntingYard.cpp.o
[ 25%] Building CXX object src/test/CMakeFiles/ArithmeticExpressionTest.dir/__/main/helper/Parser.cpp.o
[ 29%] Building CXX object src/test/CMakeFiles/ArithmeticExpressionTest.dir/__/main/helper/Utils.cpp.o
[ 33%] Building CXX object src/test/CMakeFiles/ArithmeticExpressionTest.dir/__/main/tree/BinaryTree.cpp.o
[ 37%] Building CXX object src/test/CMakeFiles/ArithmeticExpressionTest.dir/MainTest.cpp.o
[ 40%] Building CXX object src/test/CMakeFiles/ArithmeticExpressionTest.dir/database/TokenDatabaseTest.cpp.o
[ 44%] Building CXX object src/test/CMakeFiles/ArithmeticExpressionTest.dir/engine/ShuntingYardTest.cpp.o
[ 48%] Building CXX object src/test/CMakeFiles/ArithmeticExpressionTest.dir/helper/ParserTest.cpp.o
[ 51%] Building CXX object src/test/CMakeFiles/ArithmeticExpressionTest.dir/helper/UtilsTest.cpp.o
[ 55%] Building CXX object src/test/CMakeFiles/ArithmeticExpressionTest.dir/tree/BinaryTreeTest.cpp.o
[ 59%] Linking CXX executable ArithmeticExpressionTest
[ 59%] Built target ArithmeticExpressionTest
Scanning dependencies of target gmock
[ 62%] Building CXX object src/test/libs/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 66%] Linking CXX static library ../../../../lib/libgmock.a
[ 66%] Built target gmock
Scanning dependencies of target gmock_main
[ 70%] Building CXX object src/test/libs/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[ 74%] Linking CXX static library ../../../../lib/libgmock_main.a
[ 74%] Built target gmock_main
Scanning dependencies of target ArithmeticExpressionMain
[ 77%] Building CXX object src/main/CMakeFiles/ArithmeticExpressionMain.dir/Main.cpp.o
[ 81%] Building CXX object src/main/CMakeFiles/ArithmeticExpressionMain.dir/database/TokenDatabase.cpp.o
[ 85%] Building CXX object src/main/CMakeFiles/ArithmeticExpressionMain.dir/engine/ShuntingYard.cpp.o
[ 88%] Building CXX object src/main/CMakeFiles/ArithmeticExpressionMain.dir/helper/Parser.cpp.o
[ 92%] Building CXX object src/main/CMakeFiles/ArithmeticExpressionMain.dir/helper/Utils.cpp.o
[ 96%] Building CXX object src/main/CMakeFiles/ArithmeticExpressionMain.dir/tree/BinaryTree.cpp.o
[100%] Linking CXX executable ArithmeticExpressionMain
[100%] Built target ArithmeticExpressionMain
```


Run the Tets 
cd src/tests

```
./ArithmeticExpressionTest
[==========] Running 9 tests from 5 test suites.
[----------] Global test environment set-up.
[----------] 3 tests from TokenDatabaseTest
[ RUN      ] TokenDatabaseTest.when_test_database_initialized_data_is_loaded
[       OK ] TokenDatabaseTest.when_test_database_initialized_data_is_loaded (0 ms)
[ RUN      ] TokenDatabaseTest.token_assosiativity_recorded
[       OK ] TokenDatabaseTest.token_assosiativity_recorded (0 ms)
[ RUN      ] TokenDatabaseTest.token_precedence_recorded
[       OK ] TokenDatabaseTest.token_precedence_recorded (0 ms)
[----------] 3 tests from TokenDatabaseTest (3 ms total)

[----------] 2 tests from ShuntingYardTest
[ RUN      ] ShuntingYardTest.shuting_yard_alogrithm_works
[       OK ] ShuntingYardTest.shuting_yard_alogrithm_works (0 ms)
[ RUN      ] ShuntingYardTest.shuting_yard_alogrithm_works_for
[       OK ] ShuntingYardTest.shuting_yard_alogrithm_works_for (4 ms)
[----------] 2 tests from ShuntingYardTest (17 ms total)

[----------] 1 test from ParserTest
[ RUN      ] ParserTest.invalid_token_reported
GetTokenNameTokenDatabase Unsupported token Name^^GetTokenNameTokenDatabase Unsupported token Name^^GetTokenNameTokenDatabase Unsupported token Name^^GetTokenNameTokenDatabase Unsupported token Name^^GetTokenNameTokenDatabase Unsupported token Name^^[       OK ] ParserTest.invalid_token_reported (0 ms)
[----------] 1 test from ParserTest (1 ms total)

[----------] 2 tests from ExpressionsIntoTokens
[ RUN      ] ExpressionsIntoTokens.input_strings_is_parsed
[       OK ] ExpressionsIntoTokens.input_strings_is_parsed (1 ms)
[ RUN      ] ExpressionsIntoTokens.input_strings_is_parse1d
[       OK ] ExpressionsIntoTokens.input_strings_is_parse1d (1 ms)
[----------] 2 tests from ExpressionsIntoTokens (3 ms total)

[----------] 1 test from BinaryTest
[ RUN      ] BinaryTest.binar_tree_is_created
└──+
    ├──1
    └──2
[       OK ] BinaryTest.binar_tree_is_created (1 ms)
[----------] 1 test from BinaryTest (3 ms total)

[----------] Global test environment tear-down
[==========] 9 tests from 5 test suites ran. (55 ms total)
[  PASSED  ] 9 tests.

```



Run the Application 
rushi@RUSHI-PC:~/ArithmaticExpression/src/main$ ./ArithmeticExpressionMain
```
└──-
    ├──*
    │   ├──-
    │   │   └──3
    │   └──/
    │       ├──15
    │       └──-
    │           ├──7
    │           └──+
    │               ├──1
    │               └──1
    └──+
        ├──2
        └──+
            ├──1
            └──1
```
