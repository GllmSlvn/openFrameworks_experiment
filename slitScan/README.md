# SlitScan Application with OpenFrameworks

This project is an implementation of a **slit-scan effect** using OpenFrameworks. The slit-scan technique captures a sequence of frames from a live camera feed and progressively builds a new image by "scanning" vertically or horizontally.

---

## 🎥 Features

- **Real-time slit-scan effects**: 
  - Vertical scanning mode.
  - Horizontal scanning mode.
- **Live camera feed integration**.
- **Dynamic speed control** for the slit-scan effect.
- **Screenshot capture** functionality.
- Supports mirroring the camera feed for creative effects.

---

## 🛠 Setup Instructions

### 1. Prerequisites
- OpenFrameworks (tested on version 0.11.x)
- A webcam or camera device connected to your computer.

### 2. Clone the Repository and build it using project generator
```bash
cd slitscan-openframeworks
git clone https://github.com/your-username/slitscan-openframeworks.git
```

### 🎮 Controls
Key	Action
- Space	Start/stop recording the slit-scan effect.
- '1'	Switch to vertical slit-scan mode.
- '2'	Switch to horizontal slit-scan mode.
- 'S'	Toggle pause/resume during recording.
- 'x'	Capture a screenshot of the current slit-scan image.
Screenshots will be saved in the application's directory as <name><number>.png.

### ✨ How It Works
The application captures frames from the live webcam feed and progressively builds a slit-scan effect by updating rows (vertical mode) or columns (horizontal mode) one at a time.

Modes:
Vertical Mode: The image is constructed row by row from the top to the bottom.
Horizontal Mode: The image is constructed column by column from left to right.

### 🖼 Screenshots
Example screenshot of the slit-scan effect in vertical mode:
![screen_00](https://github.com/user-attachments/assets/7f89ad5f-9f02-4815-9311-11fe3701e7b1)

### 🤝 Contributing
Contributions are welcome! Feel free to open issues or submit pull requests to improve this project.

### 📝 License
This project is licensed under the MIT License.



