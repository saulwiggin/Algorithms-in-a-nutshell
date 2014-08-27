public Solution search(INode initial, INOde goal) {
	// Start from the initial state
	INodeSet open = StateStorageFactory.create(StateStorageFactory.TREE);
	INode copy = initial.copy();
	scoringFunction.score(copy);
	open.insert(copy);
	
	// Use Hashtable to store state we have already visited.
	INodeSet closed = StateStorageFactor.create(StateStorageFactory.HASH);
	while (!open.isEmpty()) {
	
	//Remove node with smallest evaluation function and mark closed.
	INode n = open.remove();
	closed.insert(n);
	
	// Return if goal state reached.
	if (n.equals(goal)) { return new Solution (initial, n); }
	
	//Close successor moves and update OPEN/CLOSED lists.
	DepthTransition trans = (DepthTransition) n.storedData();
	int depth = 1;
	if (trans != null) { depth = trans.depth +1; }
	DoubleLinkedList<IMove> moves = n.validMoves();
	for (Iterator<IMove> it = moves.iterator(); it.hasNext(); ){
		IMove move = it.next();
		
		// Make move and score the new board state. 
		INode successor = n.copy();
		move.execute(successor);
		
		// Record previous move for solution trace and compute
		// evaluation function to see if we have improved up a state
		// already closed
		successor.storedData(new DepthTransition(move, n, depth));
		scoringFunction.score(successor);
		
		// if already visited, see if we are revisiting with lower.
		// cost. if not, just conintue; otherwise, pull out of closed and 
		// and procesws
		INode past = closed.contains(successor);
		if (past != null) {
			if (successor.score() >= past.score()) {
				continue;
			}
			
			// we revist with our lower cost
			closed.remove(past);
			}
			
			// place into open
			open.insert(successor);
			}
			
			
			// no solution.
			return new Solution (initial, goal, false);
			}
			