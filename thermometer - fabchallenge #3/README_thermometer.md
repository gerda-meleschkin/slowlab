  <img src="images/slowlab_logo.jpg"/>

# Solar oven  by the Slow Lab
### by Gerda Meleschkin and Audrey Belliot

This is the documentation of our process of design and fabrication of a solar oven for FabAcademy microchallenge #1


## Concept & purpose
*How is this linked to your research areas?
Initial idea / concept of the project (what questions need to be answered?)
Propose (what is it supposed to do or not to do)

We want to explore ways in which we can live a more resilient lifestyle and try to implement systems that are less dependent on fossil fuel energy. By approaching this subject we started experimenting with a Solar Oven to see if you could use the energy of the Sun to heat up our food instead of the usual microwave or oven. With this we try to start a slow movement in which we bring awareness to our everyday habits and embrace a slower pace with processes. This will pave the way to enjoy more the moment and eliminate the rush of our daily activities by giving time for things to transform. 
We decided to explore the possibility of adding a thermometer so we could transmit the data to the user at the moment of cooking and to collect the data for future developments of the prototype. The system will work with a heat sensor wired to an arduino in which we can integrate some led lights to communicate to the user the temperature that the oven is reaching. We will also add a small LCD screen displaying the cronometer so they can know how much time their oven has been runnning and in this way make the user experience more reliable for a first approach to this alternative technologies. 
The collected data will go into a platform in which we can display it for the users and create a community in which they can share their progress and tips regarding their use of the oven. This will help us develop improvements to the prototype and understand how the user feels about these alternative systems and low-techs. 

<p float="left">
  <img src="images/areasofinterest.jpg" width="500" />
  <img src="images/projectdevelopment.jpg" width="500" />
</p>

<br>

## Planning
*Show how your team planned and executed the project.

We started by listing the tasks that needed to be done and then dividing them into priorities and iterations. We decided to start with electronics so we can get the system running and see what other questions emerge. Once we gather the needed electronics parts we can start testing in a breadboard to see program the code needed and the functions desired. For this first iteration we will focus on gathering the temperature data and showing it through the led lights. 

- Day 1: 

Making sketches and brainstorming ideas on how to represent the intended data. There will be a start button that will activate the data collection and start the timer. The same button will turn off the data collection and timer. Gathering the LED Neonpixel strip, a breadboard, jumping wires, ESP32 Feather and velleman temperature sensor. We started with the connections and testing the sensor and LED lights to see if they worked properly. We downloaded the arduino libraries for both components. For the LED lights we used the Adafruit_neopixel simple library and for the temperature sensor it's DHT sensor library. We got it up and running and then we started customizing the color of the LED lights to go from light yellow to orange and finally to red in the highest temperature. The plans for the circle board containing the electronics and display were also started so we can be able to laser cut tomorrow. 

- Day 2: text here
- Day 3: text here
- Day 4: text here

<p float="left">
  <img src="images/scetch1.jpg" width="500" />
  <img src="images/scetch2.jpg" width="500" />
</p>
*sketching*
<br>
<img src="images/lightresearch.jpg">
*light reflection simulation* on <a href="https://ricktu288.github.io/ray-optics/simulator/?en">this website</a>.

*System diagram (illustration explaining function, parts and relations)
<br>
<br>

<img src="images/system_solaroven.jpg">


## Fabrication process

### Design 
*Integrated design (how you designed it-relation between elements)
*Honest Design (use of technology in a meaningful way, in relation to the topics)
*Be creative, find solutions with materials and technology you have. 
*Explore design boundaries (base on your expertise)

Text here

### Electronics

We started testing the temperature sensor with a breaboard so we connected ground (-) and voltage (+) to USB. The pin we used is A0. 
For the LED lights we used the NeonPixel strip. We connected to ground (-), voltage (+) to usb and the pin A1. We realised this was the only pin that worked for some reason. We added a resistor in between the jumping wires of 330ohms. 

<p float="left">
  <img src="images/laser.jpg" width="330" />
  <img src="images/laser2.JPG" width="330" />
  <img src="images/gerda.jpg" width="330" />
</p>


### Process
*How did you fabricate it (process and materials)

text here  

<p float="left">
  <img src="images/videosilver.gif" width="500" />
  <img src="images/videogold.gif" width="500" />
</p>


#### text here

<p float="left">
  <img src="images/goldmaterial.jpg" width="330" />
  <img src="images/goldsheet.jpg" width="330" />
  <img src="images/goldready.jpg" width="330" />
</p>

<br>


### Material Needed
- text here
- text here


<br>

## Future development opportunities
*Listed future development opportunities for this project
- text here
- text here

<br>

## Build of Materials
Iteration process, spiral development

Text

## Setbacks
Described problems and how the team solved them


## Files
*Design and fabrication files open source or open format

- <a href="https://github.com/gerda-meleschkin/slowlab/blob/main/files/Inner%20box%20-%20solar%20oven%20v4.dxf">Inner box</a>
- <a href="https://github.com/gerda-meleschkin/slowlab/blob/main/files/slowlab_solaroven_outside_box.dxf">Outer box</a>
- <a href="https://github.com/gerda-meleschkin/slowlab/blob/main/files/Sheets%20-%20solar%20oven.dxf">Sheets</a>
- <a href="https://github.com/gerda-meleschkin/slowlab/blob/main/files/Slow%20lab%20writing.dxf">Label</a>

<br>
<br>

## Photos
*Photos of end artifact

## Our personal websites
- <a href="https://audrey-belliot.github.io/mdef/fabacademy.html">Audrey Belliot</a>
- <a href="https://gerda-meleschkin.github.io/newwebsite/fabacademy/fabacademy.html">Gerda Meleschkin</a>
- <a href="https://paula-bustos.github.io/peebee/">Paula Bustos</a>
