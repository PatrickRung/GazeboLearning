Like the title says this is my attempt of learning gazebo
# Build/ Using

`cd /GazeboLearning`
`colcon build --cmake-args -DBUILD_TESTING=ON`
`source install/setup.bash`
`ros2 launch ros_gz_example_bringup diff_drive.launch.py`

# Testing
To send a raw command over the cli to the active node you can do `ign topic -t "/Direction" -m ignition.msgs.Twist -p "linear: {x: 0.5}, angular: {z: 0.05}"`