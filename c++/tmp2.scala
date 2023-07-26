package kuplrg

// type State = Int
// type Symbol = Char
// type Alphabet = Int
// type Variable = Int
// type Word = String
// type Config = (State, Word, List[Alphabet])

object Implementation extends Template {

  // Convert a PDA with final states to a PDA with empty stacks
  /*
  기존 state와 alphabet은 1...n으로 mapping, symbol 유지
  state: q0'(0, init), q1'(n+1) 추가
  alphabet: z'(0, init) 추가
  final state: empty set

  기존 transition 모두 포함
  (state, symbol or epsilon, alphabet) -> set(state, list[alphabet])
  각각의 transition마다 state, alphabet, list[alphabet]을 mapping (yield)

  (0, None, 0) -> ((pda.initState.map), [pda.initAlphabet.map, 0])
  pda.finalState마다 n+1로 이동하는 epsilon transition
  모든 alphabet x에 대해 (n+1, None, x) -> ((n+1, []))
  */
  def pdafs2es(pda: PDA): PDA = 
    val states: Set[State] = pda.states ++ Set(pda.states.min-1, pda.states.max+1)
    val alphabets: Set[Alphabet] = pda.alphabets ++ Set(pda.alphabets.max+1)

    val is = pda.states.min-1
    val fs = pda.states.max+1
    val ia = pda.alphabets.max+1

    def stateMap(q: State): State = pda.states.toList.indexOf(q) + 1
    def alphabetMap(x: Alphabet): Alphabet = pda.alphabets.toList.indexOf(x) + 1
    def transSetMap(set: Set[(State, List[Alphabet])]): Set[(State, List[Alphabet])] =
      set.map((q, ys) => (stateMap(q), ys.map(alphabetMap)))

    val trans1: Map[(State, Option[Symbol], Alphabet), Set[(State, List[Alphabet])]] = Map((is, None, ia) -> Set((pda.initState, List(pda.initAlphabet, ia))))
    
    val trans2 = trans1 ++ pda.trans

    val trans3 = trans2 ++ (for{
      pfs <- pda.finalStates; 
      x <- alphabets
     } yield (pfs, None, x) -> Set((fs, List[Alphabet]()))).toMap
    
    val trans4 = trans3 ++ (for{
      x <- alphabets
     } yield (fs, None, x) -> Set((fs, List[Alphabet]()))).toMap

    PDA (
      states = states,
      symbols = pda.symbols,
      alphabets = alphabets,
      trans = trans4,
      initState = is,
      initAlphabet = ia,
      finalStates = Set[State](),
    )

  // Convert a PDA with empty stacks to a PDA with final states
  /*
  기존 state와 alphabet은 1...n으로 mapping, symbol 유지
  state: q0'(0, init), q1'(n+1) 추가
  alphabet: z'(0, init) 추가
  final state: n+1

  기존 transition 모두 포함
  (state, symbol or epsilon, alphabet) -> set(state, list[alphabet])
  각각의 transition마다 state, alphabet, list[alphabet]을 mapping (yield)

  (0, None, 0) -> ((pda.initState.map), [pda.initAlphabet.map, 0])
  모든 state q에 대해 (q, None, 0) -> ((n+1, []))
  */
  def pdaes2fs(pda: PDA): PDA =
    val states: Set[State] = (0 to pda.states.size+1).toSet
    val alphabets: Set[Alphabet] = (0 to pda.alphabets.size).toSet

    val initState = states.toList(pda.states.size)
    val finalState = states.toList(pda.states.size+1)
    val initAlphabet = alphabets.toList(pda.alphabets.size)

    def stateMap(q: State): State = pda.states.toList.indexOf(q) + 1
    def alphabetMap(x: Alphabet): Alphabet = pda.alphabets.toList.indexOf(x) + 1
    def transSetMap(set: Set[(State, List[Alphabet])]): Set[(State, List[Alphabet])] =
      set.map((q, ys) => (stateMap(q), ys.map(alphabetMap)))

    val trans1: Map[(State, Option[Symbol], Alphabet), Set[(State, List[Alphabet])]] = Map((initState, None, initAlphabet) -> Set((pda.initState, List(pda.initAlphabet, initAlphabet))))
    
    val trans2 = trans1 ++ pda.trans

    val trans3 = trans2 ++ (for{
      q <- pda.states
     } yield (q, None, initAlphabet) -> Set((finalState, List[Alphabet]()))).toMap

    PDA (
      states = states,
      symbols = pda.symbols,
      alphabets = alphabets,
      trans = trans3,
      initState = initState,
      initAlphabet = initAlphabet,
      finalStates = Set(finalState),
    )


  // Convert a CFG to a PDA with empty stacks
  def cfg2pdaes(cfg: CFG): PDA = 
    val states = Set(0)
    val symbols = cfg.symbols
    val alphabets: Set[Alphabet] = (0 to cfg.variables.size+cfg.symbols.size-1).toSet

    def varMap(v: Variable): Alphabet = cfg.variables.toList.indexOf(v)
    def symbolMap(a: Symbol): Alphabet = cfg.symbols.toList.indexOf(a) + cfg.variables.size

    def listMap(l: List[Variable | Symbol]): List[Alphabet] = l.map(k => (k match {
      case k: Symbol => symbolMap(k)
      case k: Variable => varMap(k)
    }))

    val initAlphabet = varMap(cfg.start)

    val trans1 = symbols.map(a =>
      ((0, Option(a), symbolMap(a)) -> Set((0, List[Alphabet]())))
    ).toMap

    val trans2 = trans1 ++ (
      cfg.productions.groupBy(_._1).map(r => 
        ((0, None, varMap(r._1)), r._2.map{case (v, li) =>
          (0, listMap(li))
        }.toSet)
      )
    )

    PDA (
      states = states,
      symbols = symbols,
      alphabets = alphabets,
      trans = trans2,
      initState = states.toList(0),
      initAlphabet = initAlphabet,
      finalStates = Set(),
    )
}
/*

val trans2 = trans1 ++ (
      cfg.productions.groupBy(_._1).map(r => 
        ((0, None, varMap(r._1)), Set((varMap(r._1), ListMap(r._2))))
      )
    )

val trans = alphabets.map(x =>
      if(x<cfg.variables.size) 
        (0, None, x) -> Set((0, List[Alphabet]()))
      else
        (0, Option(cfg.symbols.toList(x-cfg.variables.size)), x) -> Set((0, List[Alphabet]()))
    ).toMap

  */