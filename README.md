# DeckControl

#### Summary
A project using an Arduino and an Android application to control a waterfall/lights and manage the moisture level on deck plants.

#### How it works
 - An ATmega328P IC (Arduino) is used get data from the sensors and control the waterfall/lights. The Arduino and the Android application transfer data using Bluetooth. 
 - After the application has been paired to the Arduino bluetooth it will display the mositure levels of the plants in a graph, and the user will be able to turn the deck lights/waterfall on and off remotely. 
 - The Arduino sends a signal to a relay and the relay will control the lights and waterfall since they require a much high voltage. 
 - There are also physical buttons for turning the waterfall/lights on and off. When one of the buttons is pressed it will toggle the state of the waterfall/lights (on/off) and this change will be reflected in the application. 
 
 - Photos/schematics/screenshots can be found in the photos folder in the repo
 - Unfortunately I forgot to save my android studio project and source C code for the arduino so I only have the complied .apk file to upload to GitHub 
