extends Node2D

# TWO WAY FOR GETTING NODE
onready var sprite_node = get_node("Sprite")
# onready var sprite_node = $Sprite
onready var label_node = get_node("Label")

var time = 0

func _ready():
	time = 0
	
func _on_Timer_timeout():
	# SWITCH
	sprite_node.visible = !sprite_node.visible
	# true = false
	# false = true
	time += 1
	label_node.text = String(time)
