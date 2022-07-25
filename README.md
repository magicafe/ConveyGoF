Convey's game of life test

# Compile

If you want to remove the support for big integer, you can comment the compile settings **add_compile_definitions(BIG_INT)** in **CMakeLists.txt**.


# Usage
After compile finished, you should find executable file named **ConveyGoF** in **build** folder.
You can use **ConveyGoF** in the format:

**./ConveyGoF ../test.lif 10**
> Parameters:
>
> **./ConveyGoF**   : The executable file
>
> **../test.lif** : The Life 1.06 format file
>
> **10**            : Iterate count


# Comments
The version that support big integer will be much slower than normal version. Below is a comparsion use the command:

**./ConveyGoF ../glider.lif 20000**

No Big Integer Support:     0.032008s

With Big Integer Support:   1.43918s


> Environment: Macbook Pro M1 Max 32GB

# BigInt
Author: Syed Faheel Ahmad (faheel@live.in)
Project on GitHub: https://github.com/faheel/BigInt
License: MIT