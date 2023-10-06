# Shift-Counter
Application to count shifts of workers
![image](https://github.com/H1kosso/Shift-Counter/assets/115038725/adfb112f-3ab3-48ad-a403-4d28b1c62342)

## Using
User has to enter keys of workers who worked on specific days, upper part is for day shifts and lower for night. 
Then by pressing count button summary is saved to .csv file.

### Build

+ Build
```
git clone --recursive https://github.com/H1kosso/Shift-Counter.git
cd Shift-Counter
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=<YOUR_QT_SDK_DIR_PATH> -DCMAKE_BUILD_TYPE=Release -GNinja <PATH_TO_THE_REPOSITORY>
cmake --build . --config Release --target all --parallel
```
+ Use your IDE (`Qt Creator` or `CLion`) to open the project. (only **CMake** supported).
