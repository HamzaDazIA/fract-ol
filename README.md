## **fract'ol - Computer Graphics Fractals**

### **Introduction**
fract'ol is a computer graphics project focused on generating beautiful fractals using the **MiniLibX** graphical library. This project allows you to visualize the famous **Julia set** and **Mandelbrot set**, with interactive controls for zooming and modifying parameters dynamically.

---

### **Features**
✅ Supports rendering of:
  - **Mandelbrot Set**
  - **Julia Set** (with customizable parameters)
  
✅ Interactive controls:
  - **Mouse wheel**: Zoom in and out smoothly
  - **ESC key**: Exit the program
  - **Window close button**: Properly terminates the program

✅ Supports additional command-line parameters for customization

✅ Color depth representation for fractals, with potential psychedelic effects

✅ BONUS Features:
  - Additional fractals
  - Mouse-centered zoom
  - View movement via arrow keys
  - Dynamic color shifting

---

### **Installation**
To run fract'ol, ensure you have **MiniLibX** installed.

#### **Installing MiniLibX**
1. Clone the MiniLibX repository:
   ```sh
   git clone https://github.com/42Paris/minilibx-linux.git
   cd minilibx-linux
   ```
2. Compile and install:
   ```sh
   make
   sudo cp libmlx.a /usr/local/lib/
   sudo cp mlx.h /usr/local/include/
   sudo apt install libxext-dev libxrandr-dev libx11-dev libbsd-dev
   ```

#### **Compiling and Running the Project**
1. **Clone the repository**
   ```sh
   git clone https://github.com/HamzaDazIA/fractol.git
   cd fractol
   ```
2. **Compile the project**
   ```sh
   make
   ```
3. **Run the program**
   ```sh
   ./fractol [fractal_type] [optional parameters]
   ```
   Example:
   ```sh
   ./fractol mandelbrot
   ./fractol julia 0.285 0.01
   ./fractol_bonus multbrot 
   ```

---

### **Controls**
- **Mouse Scroll**: Zoom in/out  
- **ESC**: Exit  
- **Arrow Keys** *(Bonus)*: Move the view  
- **Click Close Button**: Exit  

---

### **Requirements**
- **Operating System**: Linux or macOS  
- **Compiler**: `gcc` with flags `-Wall -Wextra -Werror`  
- **Libraries**:
  - MiniLibX (`libmlx`)
  - Math Library (`-lm`)
  - ft_printf (your own implementation)

---

### **Project Structure**
```
fractol/
│── mandatoria/              # Source files
│── bonus/         # Header files
│── Makefile          # Compilation rules
│── README.md         # This file
```
