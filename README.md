
<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/mhavelka77/SLiWTP">
    <img src="assets/logo.png" alt="Logo" width="300" height="300">
  </a>

<h3 align="center">SLiWTP</h3>

  <p align="center">
    Simple Light-based Wireless Transmission Protocol   <br /> (One-way visible-light UART with esp32, LED and photodiode)
    <br />

  </p>
</div>



## About The Project
Todo: fotka


<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Requirements

* Esp32 (or similar dev board)
* Breadboard
* LED
* 330 resistor
* optic filter of same color as the LED


<p align="right">(<a href="#readme-top">back to top</a>)</p>


### Protocol


## Relation to current wireless technologies

It is good to realize, that even though this method of transmitting data does indeed use electromagnetic radiation, it does so in a completely different way from known wireless technologies as WiFi or cellular. 

Those technologies use modulations like Phase-shift keying etc. meaning they modify the carrier electromagnetic wave itself to transmit data.

What my device does is just blinking LED = using millions of electromagnetic waves (photons) to indicate a logical 1 and (ideally) no waves to indicate logical 0. Frequency of light is much higher than WiFi or any other transmission technology and is not used for this purpose for multiple reasons, one of which is for example the difficulty of modulation of such a high frequency signal.

Even though IR exists, it is actually more similar to my protocol than the one WiFi, etc. uses.


<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Martin Havelka - mhavelka77@gmail.com