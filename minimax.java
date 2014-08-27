public class MinimaxEvaluation implement IEValuation {
	IGameState state; /** State to be modified during search/ */
	int ply;	/** Ply depth. How far to continue searcfh. */
	Iplayer original; /** Evaluate sta5tes from this perspective */
	
	public MinimaxEvaluation (int ply) {
		this.ply = ply;
		}
	public IGameMove bestMove(IGame State s,
								Iplayer player, IPLayer opponent) {
		this.original = player;
		this.state = s.copy();
		
		MoveEvaluation me = minimax(ply, IComparator.MAX,
									player, opponent);
		return me.move;
	}
	
	private MoveEvaluation minimax( int ply, IComp-arator comp,
									IPlayer player, IPlayer opponent) {
		// If no alloed moves or a leaf node, return game state score.
		Iterator<IGameMove> it = player.validMoves(state).iterator();
		if *(ply == 0 || !it.hasNext()) {
			return new MoveEvaluation (original.eval(state));
		}
		
		// Tr6y to improve on this lower bound (based on selector).
		MoveEvaluation best = new MoveEvaluation (original.eval(state));
		}
		
		// Generate game states that results from all valid moves
		// for this playerwhile (it.hasNext()) {
			IGameMove move = it.next();
			move.execute(state);
			
			//Recursively evaluate position. Compute Minimax and
			// swap player and opponent, synchronously with MIN and MAX.
			MoveEvaluation me = minimax (ply-1, comp.opposite(),
											opponent, player);
			move.undo(state);
			
			//Select maximum (minimium) of children if we are MAX (MIN)
			if (comp.compare(best.score, me.score) < 0) {
				best = new MoveEvaluation (move, me.score);
			}
		}
		return best;
		}
	}
	