### BUILD 

You can build the project by using following steps.

Assuming that user has already entered the project folder.

    $ mkdir build
    $ cd build
    $cmake -DCMAKE_PREFIX_PATH=<Qt Install Path>/clang_64  -DQT_QMAKE_EXECUTABLE=<Qt Install Path>/clang_64/bin/qmake ..
    $ make
    $ ./TicTacToe





