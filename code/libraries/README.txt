Alex Mitchell
Smart Irrigation Project (SIP)
cmps 115
11/19/2014

The SIP code is spread over multiple files organized into a handful of libraries to enhance modularity. Unfortunately, the creators of Arduino don't make it as easy to develop libraries as they could have. This is great for beginners, but kind of a pain for more advanced people.

In order for an arduino file to recognize a library, it must be put in the "library" sub-directory of the Arduino install directory ("arduino_install"). Furthermore, any library which is used by a library we create must be included in the main ".ino" file. At the time our library is compiled, the compiler doesn't know where our other libraries are. To solve these issues, we:

1) We want to keep our code all in the same place within a git repository. This makes it easier to develop and use our code. We created symbolic links from the "arduino_install/libraries" directory to each of out libraries so the ardunio IDE can access our files.

For example, here's how I did it:
    Navigate to the arduino's install directory
        cd /home/alex/hacking/arduino-1.0.6

    Create a symbolic link to our project:
        ln -s /home/alex/cmps-115/Smart-Irrigation-Project/

    Navigate to the library subdirectory in the arduino's install directory:
        cd libraries

    Create a symbolic to our libraries:
        ln -s ../Smart-Irrigation-Project/code/libraries/SIP* ./

    Macs are unix based, so I expect these commands will work too. I don't know the equivalent in Windows; maybe create shortcuts to our libraries and then move those shortcuts into the "arduino_install/library directory".


2) We 

