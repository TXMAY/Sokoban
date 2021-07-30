extends Label

onready var flag_node = get_node("../Flag")
onready var car_node = get_node("../Car")

var distance = 0

func _ready():
	distance = 0
	
	
func _process(delta):
	distance = flag_node.transform.get_origin().x - car_node.transform.get_origin().x
	text = String("목표 지점까지 %d m 남았습니다." % distance)
