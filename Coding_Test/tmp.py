import tkinter as tk

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
        gauge_width = gauge_canvas.winfo_width()
        gauge_height = gauge_canvas.winfo_height()
        gauge_fill = (remaining_time / initial_time) * gauge_width
        gauge_canvas.create_rectangle(0, 0, gauge_fill, gauge_height, fill="red", tags="gauge")

        time_label.after(1000, countdown)  # Update every 1 second
    else:
        time_label.config(text="Time's up!")

# Create the main window
window = tk.Tk()
window.title("Timer with Gauge Bar")

# Create and position the widgets
entry = tk.Entry(window, font=("Arial", 14))
entry.pack(pady=10)

start_button = tk.Button(window, text="Start", command=start_timer, font=("Arial", 14))
start_button.pack(pady=5)

time_label = tk.Label(window, text="00:00", font=("Arial", 40))
time_label.pack(pady=20)

gauge_canvas = tk.Canvas(window, width=300, height=20, bg="white")
gauge_canvas.pack(pady=10)

# Set the initial gauge bar
initial_time = 60  # Initial time in seconds
gauge_canvas.create_rectangle(0, 0, gauge_canvas.winfo_width(), gauge_canvas.winfo_height(), fill="red", tags="gauge")

# Start the main loop
window.mainloop()