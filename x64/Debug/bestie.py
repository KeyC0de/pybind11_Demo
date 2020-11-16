print( "test.py loaded" )

import embedded_module as em2
em2.talkToMe()
em2.setCounter( 200 )
print( em2.getCounter() )

#def callFromCpp( vec : em2.Vec2 ):
def callFromCpp( vec ):
	print( "Called from C++! ({},{})\n".format( vec.x, vec.y ) )