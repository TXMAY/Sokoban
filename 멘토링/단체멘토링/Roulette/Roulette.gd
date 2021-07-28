extends Sprite

var rotation_speed = 0.0
var is_cliked = false

# Initialize When Game Ready
func _ready():
	rotation_speed = 0.0
	is_cliked = false

# Process Function
func _process(delta):
	if !is_cliked:
		rotation_speed *= 0.9994
	rotation_degrees += rotation_speed

# Get Input Event
func _input(event):
	if event.is_action_pressed("ui_mouse_left"):
		rotation_speed = 10.0
		is_cliked = true
	elif event.is_action_released("ui_mouse_left"):
		is_cliked = false
