# Tabular-data
A simple language for working with tables of numbers that can be useful in statistical analysis.

This language consists of a set of commands that are described below.

When the program is executed, the > sign is printed on the output, which means that the program is waiting to receive user instructions.
## Commands
### create
You can create a table using the ```create``` command. For example, the following command creates a table called name_table with 5 columns : ``` create table_name 5```

Create as many tables as you can; In addition, the names of the tables are unique.

### insert
You can add a new row to the table using the ```insert``` command. This row must have the number of columns in the table. For example :

```insert table_name [12 1.12 15 117 20]```

### display
You can use the ```display``` command to view the data in a table as follows :

```
> insert table_name [78 -55 1 0 10]
> display table_name
table table_name with 5 columns and 2 rows
[0] [12 1.12 15 117 20]
[1] [78 -55 1 0 10]
```

### drop
You can delete a custom row using the ```drop``` command. The following command deletes the first line of table table_name : 

```
> drop table_name 0
> display table_name
table table_name with 5 columns and 1 rows
[0] [78 -55 1 0 10]
```

If you do not enter any row number, the whole table will be deleted.

### merge
The ```merge``` command takes the names of two tables with the same number of columns and adds the second data to the first end. For example :

```
> create t1 5
> insert t1 [2 19 1400 12 13]
> merge table_name t1
> display table_name
table table_name with 5 columns and 2 rows
[0] [78 -55 1 0 10]
[1] [2 19 1400 12 13]
```

### sort
The ```sort``` command receives the name of a table and the number of a column and sorts the table according to that column in ascending order. For example, this command sorts table table_name based on its one column :
```
> sort table_name 0
> display table_name
table table_name with 5 columns and 2 rows
[0] [2 19 1400 12 13]
[1] [78 -55 1 0 10]
```

### statistics
The ```statistics``` command displays the least element, most element, sum, mean, variance, and standard deviation for each column in the table. For example : 

```
> statistics table_name
[min ] [2 -55 1 0 10]
[max ] [78 19 1400 12 13]
[sum ] [80 -36 1401 12 23]
[mean] [40 -18 700.5 6 11.5]
[var ] [1444 1369 489300.25 36 2.25]
[std ] [38 37 699.5 6 1.5]
```

### export
Using the ```export``` command, you can save a table in a file with the desired name. For example : ``` export table_name test.txt```

### import
Using the ```import``` command, you can import data from a file into a new or existing table. For example : ``` import t2 test.txt```

### exit
The program ends with the ```exit``` command.

### clear
The ```clear``` command clears the page.

> ***Note : The number of spaces as well as uppercase and lowercase letters are not important for the program.***

## Prerequisite
[CMake](https://cmake.org/) is used to control the software compilation process using simple platform and compiler independent configuration files, and generate native makefiles and workspaces that can be used in the compiler environment of your choice.

Of course, you can also compile without using cmake.

## Compatibility
You should be able to run this program anywhere. For the compiling process, both of [GCC](https://gcc.gnu.org/) and [Clang](https://clang.llvm.org/) should work.
### Tested Environments
- OS:  [Microsoft](https://www.microsoft.com/uk-ua/) Windows 10 Pro x64
- Compiler: [GCC](https://gcc.gnu.org/) C++ Compiler (8.1.0)
- Building: [CMake](https://cmake.org/) build system (3.19.0-rc1)

## Cloning
```
git clone https://github.com/MohammadRezaNouri/Tabular-data
```

## Installation
### Windows
open the cmd or PowerShell and go to files directory with cd command and execute the following commands :

- Compile

    With [CMake](https://cmake.org/)
    ```bash
    cd build
    cmake ..
    cmake --build .
    cd Debug
    ./app
    ```
    Without [CMake](https://cmake.org/)
    
    Put all .h and .cpp files in one folder.
    ```bash
    g++ *.cpp -o app -O2
    ./app
    ```

- Run
    ```\Tabular-data\build\Debug\app.exe```

### Linux
open the terminal and go to file directory with cd command and execute the following commands :
- Compile

    With [CMake](https://cmake.org/)
    ```bash
    rm -r build
    mkdir build
    cd build
    cmake ..
    make
    ./app
    ```
    Without [CMake](https://cmake.org/)
    
    Put all .h and .cpp files in one folder.
    ```bash
    g++ *.cpp -o app -O2
    ./app
    ```

## Usage
Your contributions are always welcome.

## In the future
Become a graphic application.

## Contributing
Statistical analysis.

## Thanks to
#### [Mr Amirabbas Asadi](https://github.com/amirabbasasadi)
#### [Mr Ahmad Jafari](https://github.com/jafari-dev)

## License
Licensed under GPLv3. See [LICENSE.md](https://github.com/MohammadRezaNouri/Tabular-data/blob/main/LICENSE.md).
