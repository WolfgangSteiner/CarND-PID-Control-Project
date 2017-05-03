# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
## Describe the effect each of the P, I, D components had in your implementation.
- The P error term is proportional to the cross-track error (CTE). This part of the the controller enables the vehicle
to quickly react to changes in the CTE, e.g. due to sharp turns. On the other hand, relying on the P term alone will
lead to the vehicle overshooting the target trajectory which can even lead to unstable behavior. Increasing the weight
Kp will enable the vehicle to better follow sharp turns but may result in oscillation around the intended trajectory.

- The D error term is proportional to the _change_ of the CTE. By adding this term to the controller, it becomes possible
to dampen the potentially unstable behavior of the proportional control term. Thus, if we want to achieve a driving 
behavior that is able to follow sharp turns by increasing Kp, we would also need to stabilize by increasing Kd. Otherwise,
oscillations would occur on straight parts of the road. This PD control behavior would be sufficient for keeping 
the vehicle on the road, if there were no external forces or internal biases to the steering.

- Finally, the I error term is proportional to the _integral_ of the CTE. If the vehicle has a bias in its steering 
mechanism, or if there were a constant cross wind, a PD controller alone would not be able to keep the vehicle on the
intended trajectory path. A constant error would result, which would correspond to the vehicle driving at some lateral 
distance to the trajectory. To compensate for this, the integral term of the PID is utilized, which will increase if 
a constant error should occur, thus minimizing it and pushing the car back towards the intended trajectory.
 
## Describe how the final hyperparameters were chosen.
After implementing the PID equations, I first started out with a P controller by setting the parameters Kd and Ki to zero.
This allowed me to find a value for Kp that had the correct magnitude. This, of course resulted in an undesirable 
oscillating driving behavior and the car did not complete the track. I then gradually increased Kd until the oscillations
had been successfully damped. This resulted in the car not being able to follow the sharp turns as it reacted too slowly.
So I iterated by increasing Kp and Kd until the car was able to complete the track. Finally, I focused on the parameter
Ki. As I was not able to detect any major biases in the car's steering behavior (it stayed exactly in the center
of the straight bridge), I introduced one by adding 0.25 to the final steering angle passed to the simulator.
This resulted in the car drifting to the right side of the road, while 
still being able to complete the track. This artificial steering bias allowed me to find a value for Ki that resulted in the
car keeping to the center of the road again.
 
The final values used by my implementation are: Kp = 0.225, Ki = 0.001, and Kd = 16.0.
