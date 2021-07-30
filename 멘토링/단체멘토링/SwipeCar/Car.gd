extends Sprite
onready var audio_sourcce = get_node("../Audio")

var car_speed = 0.0
var start_position = Vector2(0.0, 0.0)
var is_clicked = false

func _ready():
	car_speed = 0.0
	is_clicked = false
	
func _process(delta):
	if !is_clicked:
		car_speed *= 0.87
	translate(Vector2(car_speed, 0.0))
	
func _input(event):
	if event.is_action_pressed("ui_mouse_left"):
		start_position = get_viewport().get_mouse_position()
		print("START POSITION : ", start_position)
		is_clicked = true
	elif event.is_action_released("ui_mouse_left"):
		var end_position = get_viewport().get_mouse_position()
		var swipe_length = (end_position.x - start_position.x)
		car_speed = swipe_length / 5.0
		audio_sourcce.play()
		is_clicked = false
