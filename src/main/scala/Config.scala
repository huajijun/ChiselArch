import junctions.NastiBundleParameters



case class Config(core: CoreConfig, cache: CacheConfig, nasti: NastiBundleParameters)


object MiniConfig{
	def apply(): Config = {
		val xlen = 32
		Config(
			core = CoreConfig(
				xlen = xlen,
				makeAlu = new AluSimple(_),
				makeBrCond = new BrCondSimple(_),
				makeImmGen = new ImmGenWire(_)
			),

			cache = CacheConfig(
				nWays = 1,
				nSets = 256,
				blockBytes = 4 *(xlen / 8)
			),

			nasti = NastiBundleParameters(
				addrBits = 32,
				dataBits = 64,
				idBits	 = 5
			)
		)
	}
}