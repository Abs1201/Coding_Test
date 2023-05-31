import tkinter as tk
import math

def start_timer():
    global remaining_time
    remaining_time = int(entry.get())  # Get the input time in seconds
    countdown()

def countdown():
    global remaining_time
    if remaining_time > 0:
        minutes = remaining_time // 60
        seconds = remaining_time % 60
        time_label.config(text=f"{minutes:02d}:{seconds:02d}")
        remaining_time -= 1
        
        # Update the gauge bar
        gauge_canvas.delete("gauge")
        gauge_radius = 80
        gauge_width = 20
        gauge_start_angle = 90  # Start the arc from the top (12 o'clock position)
        gauge_end_angle = gauge_start_angle - (360 * remaining_time / initial_time)
        gauge_canvas.create_arc(
            10, 10, gauge_radius*2 + 10, gauge_radius*2 + 10,
            start=gauge_start_angle, extent=-gauge_end_angle,
            width=gauge_width, outline="red", style=tk.ARC, tags="gauge"
        )

        time_label.place(in_=gauge_canvas, relx=0.5, rely=0.5, anchor="center")  # Position the time label at the center of the gauge canvas

        time_label.after(1000, countdown)  # Update every 1 second
    else:
        time_label.config(text="Time's up!")

# Create the main window
window = tk.Tk()
window.title("Timer with Circular Gauge Bar")

# Create and position the widgets
entry = tk.Entry(window, font=("Arial", 14))
entry.pack(pady=10)

start_button = tk.Button(window, text="Start", command=start_timer, font=("Arial", 14))
start_button.pack(pady=5)

gauge_canvas = tk.Canvas(window, width=200, height=200, bg="white")
gauge_canvas.pack(pady=10)

time_label = tk.Label(gauge_canvas, text="00:00", font=("Arial", 40), bg="white")

# Set the initial gauge bar
initial_time = 60  # Initial time in seconds
gauge_radius = 80
gauge_width = 20
gauge_canvas.create_arc(
    10, 10, gauge_radius*2 + 10, gauge_radius*2 + 10,
    start=90, extent=-360,
    width=gauge_width, outline="red", style=tk.ARC, tags="gauge"
)

# Start the main loop
window.mainloop()
