public class AlphaBetaEvaluation implement IEvaluation {
	IGameState state;	/** State to be modified during search. */
	int ply;			/** Ply depth. How far to continue search. */
	
	public AlphaBetaEvaluation (int ply) {this.ply = ply;}
	
	public IGameMove bestMove (IGameState s,
								IPlayer player, IPlayer opponent) {
		this.state = s.copy();
		MoveEvaluation move= alphabeta(ply, player, opponent,
										MoveEvaluation.minimum(), MoveEvaluation.maximum());
		return move.move;
		}
		
		private MoveEvaluation alphabeta (int ply, IPlayer player, IPlayer opponent,
											int alpha, int beta) {
			// If no moves, return evaluation of board from player's persepctive.
			Iterator<IGameMove> it = player.validMoves(state).iterator();
			if (ply == 0 || !it.hasNext()) {
				return new MoveEvaluation (player.eval(state));
			}
			
			// Select "maximum of negative value of children" that improves alpha
			MoveEvaluation best = new MoveEvaluation(alpha);
			while(it.hasNext()) {
				IGameMove move = it.next();
				
				// Recursively evaluate position.
				move.execute(state);
				MoveEvaluation me = alphabeta (ply-1, opponent, player, -beta, -alpha);
				move.undo(state);
				
				//. If improved upon alpha, keep track of this move.
				if (-me.score > alpha) {
					alpha = -me.score;
					best = new MoveEvaluation (move, alpha);
				}
				if (alpha >= beta ) { return best; } // search no longer productive
				}
				return best;
			}
		}
		