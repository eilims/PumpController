%Daniel Benusovich
%27 May 2018
%This simulation is done to verify the the equations generated via
%extrapolation through experimentation. All relevant plots will be
%generated then a controller introduced to see watering time responses


%Generating plot for Sensor Readings -> VWC required to be reintroduced
%into the soil
%Full range of possible sensor values
sensorReading = 0:1:1023;
%Equation for generating required VMC to be returned to soil
vwcRequired = (0.771 * exp(.00393*sensorReading))/100;

%Plotting results
plot(sensorReading, vwcRequired);
xlabel('Moisture Reading');
ylabel('VWC Required');


%Generating plot for VWC required -> watering time
%This is dependant on the size of the holes and planter so be sure to
%recalibrate it for every system! Or write the software to configure itself
%but one step at a time.

figure
waterTime = 306 * vwcRequired + .00103;
plot(vwcRequired, waterTime);
xlabel('VWC Required');
ylabel('Watering Time');


%Generating nonPID controller response

