# 3D Particle Simulation - openFrameworks

This application is a 3D particle simulation built using the openFrameworks. Each particle is influenced by gravity, an attraction force towards the mouse position, and other simple physical forces. The particles are contained within a cube, whose size is adjustable independently from the number of particles.

## Features
- 3D Particle System: Each particle has a position, velocity, mass, and lifetime.
- Attraction to Mouse: Particles are attracted to the mouse position within the window.
- Gravity: Particles are affected by gravity, with each particle potentially having its own gravity value.
- Dynamic Particle Colors: The color of the particles evolves based on their lifetime.
- 3D Cube: The particles are confined within a cube, the size of which is configurable, independent of the number of particles.
- Performance Optimization for CPU: The particle rendering is optimized for high performance, even with a large number of particles (up to 35 000 at 120 FPS).

## Prerequisites
openFrameworks (version 0.11.0 or higher)
A compatible C++ compiler (e.g., Xcode, Visual Studio, or GCC)

## Installation
Clone this repository:

```sh
git clone https://github.com/your-username/particle-simulation.git
```

Download and Install openFrameworks: If you haven't already, follow the instructions on the openFrameworks website to download and set up openFrameworks.

#### Open the Project: 
Built the projet using project generator
Navigate to the particle-simulation folder, and open the project in your chosen IDE:

Build and Run: Once the project is open in your IDE, build and run it as you would with any openFrameworks project.


## Usage
- Interaction: The particles are attracted to the mouse position within the window. Moving the mouse will change the direction and force applied to the particles.
- Particle Lifespan: Particles have a lifespan that decreases over time. When their lifetime reaches zero, they "die" and are reset to a new position.
- Gravity: Each particle is affected by gravity, which pulls them downwards. The strength of gravity can vary for each particle.

## Performance Tips
If you are experiencing performance issues, try reducing the number of particles by lowering the numParticles variable.
The simulation is optimized for high performance, but the number of particles and the complexity of the physics can still affect frame rate.

## ScreenShot
![out](https://github.com/user-attachments/assets/b1976241-7a29-47b2-8447-24fb0ac91013)

## Acknowledgments
This project uses openFrameworks, a powerful creative coding framework.
Special thanks to the openFrameworks community for providing helpful resources and support.

## License
This project is open source and available under the MIT License. 
