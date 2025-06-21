<?php

namespace App\Http\Controllers;

use App\Models\Book;
use App\Models\User;
use Illuminate\Http\Request;

class BookController extends Controller
{
    public function index(Request $request){
        $data = Book::select('id','name','user_id')
        // ->with([
        //     'user' => function($query){
        //         $query->select('id','name');
        //     }
        // ])
        // ->whereRelation('user','name','like', "%Prof%")
        ->get();

        return view('book', compact('data'));
    }

    public function getUser(){
        $data = User::select('id', 'name')
        ->withCount('book')
        ->get();

        return $this->ApiResponse("success", $data);
    }

    public function store(Request $request){
        $request->validate([
            'name' => 'required'
        ]);

        try {
            $book = new Book();
            $book->name = $request->name;
            $book->user_id=1;
            $book->save();
            
            return $this->ApiResponse("success");
        } catch (\Throwable $th) {
            return $this->ApiResponse($th->getMessage(),NULL,500);
        }
    }
}
