# DirectorySizeChecker
Checking size of the directory(-ies) using threadpool</br>

# Build
cmake . && make</br>

# Usage
./DSC -t \<threads\></br></br>

stdin << path to the directory which size you want to know</br>
stdin << :exit to exit after ending of all calculations</br>
stdin << :cancel to clear queue and cancel all previous tasks
