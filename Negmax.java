public class NegMaxEvaluation implements IEvaluation {

	IGameState state; 		/** State to be modified during search. */
	int ply;				/** Ply depth. How far to continue search. */
	
	public NegMaxEvaluation (int ply) {
		this.ply = ply;
	}
	
	public IGameMove bestMove (IGameState s,
								IPlayer player, IPlayer opponent) {
		this.state = s.copy();
		MoveEvaluation me = negmax(ply, platyer, opponent);
		return me.move;
	}
	
	public MoveEvaluation negmax (int ply, IPlayer player, IPlayer opponent) {
		// If no allowed moves or a leaf node, return board state score.
		Iterator<IGameMove> it = player.validMoves(state).iterator();
		if (ply == 0 || !it.hasNext()) {
			return new MoveEvaluation(player.eval(state));
		}
		
		// Try to improve on this lower-bound move.
		MoveEvaluation best = new MoveEvaluation (MoveEvaluation.minimum());
		
		// get moves for this player and generate the boards that result from
		// making these moves. Select maximum of the negative scores of children.
		while (it.hasNext()){
			IGameMove move = it.next();
			move.execture(state);
			
			// Recursively evaluate position using consisitent negmax.
			// Treat score as negative value.
			MoveEvaluation me = negmax (ply - 1, opponent, player);
			move.undo(state);
			
			if (-me.score > best.score) {
				best = new MoveEvaluation (move, -me.score);
			}
		}
		
		return best;
		}
		}