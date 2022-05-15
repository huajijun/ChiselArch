
import chisel3.stage.ChiselGeneratorAnnotation
import firrtl.options.TargetDirAnnotation

// need modify 
object Main extend App {
	val config = MiniConfig()
	new Tile(config.core, config.nasti, config.cache)
}

