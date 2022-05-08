import chisel3._
object Control {
	// br_type
	val BR_XXX = 0.U(3.W)
	val BR_LTU = 1.U(3.W)
	val BR_LT = 2.U(3.W)
	val BR_EQ = 3.U(3.W)
	val BR_GEU = 4.U(3.W)
	val BR_GE = 5.U(3.W)
	val BR_NE = 6.U(3.W)
}