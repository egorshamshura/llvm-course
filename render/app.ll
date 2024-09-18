; ModuleID = 'app.c'
source_filename = "app.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: argmemonly nofree norecurse nosync nounwind writeonly uwtable
define dso_local void @init(ptr nocapture noundef writeonly %0) local_unnamed_addr #0 {
  tail call void @llvm.memset.p0.i64(ptr noundef nonnull align 1 dereferenceable(131072) %0, i8 0, i64 131072, i1 false), !tbaa !5
  %2 = getelementptr inbounds [256 x i8], ptr %0, i64 1, i64 6
  store i8 1, ptr %2, align 1, !tbaa !5
  %3 = getelementptr inbounds [256 x i8], ptr %0, i64 1, i64 7
  store i8 1, ptr %3, align 1, !tbaa !5
  %4 = getelementptr inbounds [256 x i8], ptr %0, i64 2, i64 6
  store i8 1, ptr %4, align 1, !tbaa !5
  %5 = getelementptr inbounds [256 x i8], ptr %0, i64 2, i64 7
  store i8 1, ptr %5, align 1, !tbaa !5
  %6 = getelementptr inbounds [256 x i8], ptr %0, i64 11, i64 6
  store i8 1, ptr %6, align 1, !tbaa !5
  %7 = getelementptr inbounds [256 x i8], ptr %0, i64 11, i64 7
  store i8 1, ptr %7, align 1, !tbaa !5
  %8 = getelementptr inbounds [256 x i8], ptr %0, i64 11, i64 8
  store i8 1, ptr %8, align 1, !tbaa !5
  %9 = getelementptr inbounds [256 x i8], ptr %0, i64 12, i64 5
  store i8 1, ptr %9, align 1, !tbaa !5
  %10 = getelementptr inbounds [256 x i8], ptr %0, i64 12, i64 9
  store i8 1, ptr %10, align 1, !tbaa !5
  %11 = getelementptr inbounds [256 x i8], ptr %0, i64 13, i64 4
  store i8 1, ptr %11, align 1, !tbaa !5
  %12 = getelementptr inbounds [256 x i8], ptr %0, i64 13, i64 10
  store i8 1, ptr %12, align 1, !tbaa !5
  %13 = getelementptr inbounds [256 x i8], ptr %0, i64 14, i64 4
  store i8 1, ptr %13, align 1, !tbaa !5
  %14 = getelementptr inbounds [256 x i8], ptr %0, i64 14, i64 10
  store i8 1, ptr %14, align 1, !tbaa !5
  %15 = getelementptr inbounds [256 x i8], ptr %0, i64 15, i64 7
  store i8 1, ptr %15, align 1, !tbaa !5
  %16 = getelementptr inbounds [256 x i8], ptr %0, i64 16, i64 5
  store i8 1, ptr %16, align 1, !tbaa !5
  %17 = getelementptr inbounds [256 x i8], ptr %0, i64 16, i64 9
  store i8 1, ptr %17, align 1, !tbaa !5
  %18 = getelementptr inbounds [256 x i8], ptr %0, i64 17, i64 6
  store i8 1, ptr %18, align 1, !tbaa !5
  %19 = getelementptr inbounds [256 x i8], ptr %0, i64 17, i64 7
  store i8 1, ptr %19, align 1, !tbaa !5
  %20 = getelementptr inbounds [256 x i8], ptr %0, i64 17, i64 8
  store i8 1, ptr %20, align 1, !tbaa !5
  %21 = getelementptr inbounds [256 x i8], ptr %0, i64 18, i64 7
  store i8 1, ptr %21, align 1, !tbaa !5
  %22 = getelementptr inbounds [256 x i8], ptr %0, i64 21, i64 6
  store i8 1, ptr %22, align 1, !tbaa !5
  %23 = getelementptr inbounds [256 x i8], ptr %0, i64 21, i64 5
  store i8 1, ptr %23, align 1, !tbaa !5
  %24 = getelementptr inbounds [256 x i8], ptr %0, i64 21, i64 4
  store i8 1, ptr %24, align 1, !tbaa !5
  %25 = getelementptr inbounds [256 x i8], ptr %0, i64 22, i64 6
  store i8 1, ptr %25, align 1, !tbaa !5
  %26 = getelementptr inbounds [256 x i8], ptr %0, i64 22, i64 5
  store i8 1, ptr %26, align 1, !tbaa !5
  %27 = getelementptr inbounds [256 x i8], ptr %0, i64 22, i64 4
  store i8 1, ptr %27, align 1, !tbaa !5
  %28 = getelementptr inbounds [256 x i8], ptr %0, i64 23, i64 3
  store i8 1, ptr %28, align 1, !tbaa !5
  %29 = getelementptr inbounds [256 x i8], ptr %0, i64 23, i64 7
  store i8 1, ptr %29, align 1, !tbaa !5
  %30 = getelementptr inbounds [256 x i8], ptr %0, i64 25, i64 2
  store i8 1, ptr %30, align 1, !tbaa !5
  %31 = getelementptr inbounds [256 x i8], ptr %0, i64 25, i64 3
  store i8 1, ptr %31, align 1, !tbaa !5
  %32 = getelementptr inbounds [256 x i8], ptr %0, i64 25, i64 7
  store i8 1, ptr %32, align 1, !tbaa !5
  %33 = getelementptr inbounds [256 x i8], ptr %0, i64 25, i64 8
  store i8 1, ptr %33, align 1, !tbaa !5
  %34 = getelementptr inbounds [256 x i8], ptr %0, i64 35, i64 4
  store i8 1, ptr %34, align 1, !tbaa !5
  %35 = getelementptr inbounds [256 x i8], ptr %0, i64 35, i64 5
  store i8 1, ptr %35, align 1, !tbaa !5
  %36 = getelementptr inbounds [256 x i8], ptr %0, i64 36, i64 4
  store i8 1, ptr %36, align 1, !tbaa !5
  %37 = getelementptr inbounds [256 x i8], ptr %0, i64 36, i64 5
  store i8 1, ptr %37, align 1, !tbaa !5
  ret void
}

; Function Attrs: argmemonly mustprogress nocallback nofree nosync nounwind willreturn
declare void @llvm.lifetime.start.p0(i64 immarg, ptr nocapture) #1

; Function Attrs: argmemonly nofree norecurse nosync nounwind writeonly uwtable
define dso_local void @clear(ptr nocapture noundef writeonly %0) local_unnamed_addr #0 {
  tail call void @llvm.memset.p0.i64(ptr noundef nonnull align 1 dereferenceable(131072) %0, i8 0, i64 131072, i1 false), !tbaa !5
  ret void
}

; Function Attrs: nounwind uwtable
define dso_local void @dump(ptr nocapture noundef readonly %0) local_unnamed_addr #2 {
  br label %2

2:                                                ; preds = %1, %7
  %3 = phi i64 [ 0, %1 ], [ %8, %7 ]
  %4 = trunc i64 %3 to i32
  %5 = trunc i64 %3 to i32
  br label %10

6:                                                ; preds = %7
  tail call void (...) @simFlush() #7
  ret void

7:                                                ; preds = %18
  %8 = add nuw nsw i64 %3, 1
  %9 = icmp eq i64 %8, 512
  br i1 %9, label %6, label %2, !llvm.loop !8

10:                                               ; preds = %2, %18
  %11 = phi i64 [ 0, %2 ], [ %19, %18 ]
  %12 = getelementptr inbounds [256 x i8], ptr %0, i64 %3, i64 %11
  %13 = load i8, ptr %12, align 1, !tbaa !5
  %14 = icmp eq i8 %13, 1
  %15 = trunc i64 %11 to i32
  br i1 %14, label %16, label %17

16:                                               ; preds = %10
  tail call void @simPutPixel(i32 noundef %5, i32 noundef %15, i32 noundef 0) #7
  br label %18

17:                                               ; preds = %10
  tail call void @simPutPixel(i32 noundef %4, i32 noundef %15, i32 noundef -1) #7
  br label %18

18:                                               ; preds = %16, %17
  %19 = add nuw nsw i64 %11, 1
  %20 = icmp eq i64 %19, 256
  br i1 %20, label %7, label %10, !llvm.loop !10
}

declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #3

declare void @simFlush(...) local_unnamed_addr #3

; Function Attrs: mustprogress nofree norecurse nosync nounwind readnone willreturn uwtable
define dso_local i32 @get(i32 noundef %0, i32 noundef %1) local_unnamed_addr #4 {
  %3 = srem i32 %0, %1
  %4 = add nsw i32 %3, %1
  %5 = srem i32 %4, %1
  ret i32 %5
}

; Function Attrs: argmemonly nofree norecurse nosync nounwind uwtable
define dso_local void @next_generation(ptr nocapture readnone %0, ptr nocapture noundef %1, ptr nocapture noundef %2) local_unnamed_addr #5 {
  br label %4

4:                                                ; preds = %3, %10
  %5 = phi i64 [ 0, %3 ], [ %8, %10 ]
  %6 = add nuw i64 %5, 511
  %7 = and i64 %6, 511
  %8 = add nuw nsw i64 %5, 1
  %9 = and i64 %8, 511
  br label %12

10:                                               ; preds = %54
  %11 = icmp eq i64 %8, 512
  br i1 %11, label %58, label %4, !llvm.loop !11

12:                                               ; preds = %4, %54
  %13 = phi i64 [ 0, %4 ], [ %23, %54 ]
  %14 = add nuw i64 %13, 255
  %15 = and i64 %14, 255
  %16 = getelementptr inbounds [256 x i8], ptr %1, i64 %7, i64 %15
  %17 = load i8, ptr %16, align 1, !tbaa !5
  %18 = sext i8 %17 to i32
  %19 = getelementptr inbounds [256 x i8], ptr %1, i64 %7, i64 %13
  %20 = load i8, ptr %19, align 1, !tbaa !5
  %21 = sext i8 %20 to i32
  %22 = add nsw i32 %21, %18
  %23 = add nuw nsw i64 %13, 1
  %24 = and i64 %23, 255
  %25 = getelementptr inbounds [256 x i8], ptr %1, i64 %7, i64 %24
  %26 = load i8, ptr %25, align 1, !tbaa !5
  %27 = sext i8 %26 to i32
  %28 = add nsw i32 %22, %27
  %29 = getelementptr inbounds [256 x i8], ptr %1, i64 %5, i64 %15
  %30 = load i8, ptr %29, align 1, !tbaa !5
  %31 = sext i8 %30 to i32
  %32 = add nsw i32 %28, %31
  %33 = getelementptr inbounds [256 x i8], ptr %1, i64 %5, i64 %24
  %34 = load i8, ptr %33, align 1, !tbaa !5
  %35 = sext i8 %34 to i32
  %36 = add nsw i32 %32, %35
  %37 = getelementptr inbounds [256 x i8], ptr %1, i64 %9, i64 %15
  %38 = load i8, ptr %37, align 1, !tbaa !5
  %39 = sext i8 %38 to i32
  %40 = add nsw i32 %36, %39
  %41 = getelementptr inbounds [256 x i8], ptr %1, i64 %9, i64 %13
  %42 = load i8, ptr %41, align 1, !tbaa !5
  %43 = sext i8 %42 to i32
  %44 = add nsw i32 %40, %43
  %45 = getelementptr inbounds [256 x i8], ptr %1, i64 %9, i64 %24
  %46 = load i8, ptr %45, align 1, !tbaa !5
  %47 = sext i8 %46 to i32
  %48 = add nsw i32 %44, %47
  switch i32 %48, label %53 [
    i32 3, label %54
    i32 2, label %49
  ]

49:                                               ; preds = %12
  %50 = getelementptr inbounds [256 x i8], ptr %1, i64 %5, i64 %13
  %51 = load i8, ptr %50, align 1, !tbaa !5
  %52 = icmp eq i8 %51, 1
  br i1 %52, label %54, label %53

53:                                               ; preds = %12, %49
  br label %54

54:                                               ; preds = %49, %12, %53
  %55 = phi i8 [ 0, %53 ], [ 1, %12 ], [ 1, %49 ]
  %56 = getelementptr inbounds [256 x i8], ptr %2, i64 %5, i64 %13
  store i8 %55, ptr %56, align 1, !tbaa !5
  %57 = icmp eq i64 %23, 256
  br i1 %57, label %10, label %12, !llvm.loop !12

58:                                               ; preds = %10, %119
  %59 = phi i64 [ %120, %119 ], [ 0, %10 ]
  %60 = shl nuw nsw i64 %59, 8
  %61 = add nuw i64 %60, 256
  %62 = getelementptr i8, ptr %2, i64 %61
  %63 = getelementptr i8, ptr %2, i64 %60
  %64 = getelementptr i8, ptr %1, i64 %61
  %65 = getelementptr i8, ptr %1, i64 %60
  %66 = icmp ult ptr %65, %62
  %67 = icmp ult ptr %63, %64
  %68 = and i1 %66, %67
  br i1 %68, label %122, label %69

69:                                               ; preds = %58
  %70 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 0
  %71 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 0
  %72 = load <16 x i8>, ptr %71, align 1, !tbaa !5, !alias.scope !13
  %73 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 16
  %74 = load <16 x i8>, ptr %73, align 1, !tbaa !5, !alias.scope !13
  store <16 x i8> %72, ptr %70, align 1, !tbaa !5, !alias.scope !16, !noalias !13
  %75 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 16
  store <16 x i8> %74, ptr %75, align 1, !tbaa !5, !alias.scope !16, !noalias !13
  store <16 x i8> zeroinitializer, ptr %71, align 1, !tbaa !5, !alias.scope !13
  store <16 x i8> zeroinitializer, ptr %73, align 1, !tbaa !5, !alias.scope !13
  %76 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 32
  %77 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 32
  %78 = load <16 x i8>, ptr %77, align 1, !tbaa !5, !alias.scope !13
  %79 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 48
  %80 = load <16 x i8>, ptr %79, align 1, !tbaa !5, !alias.scope !13
  store <16 x i8> %78, ptr %76, align 1, !tbaa !5, !alias.scope !16, !noalias !13
  %81 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 48
  store <16 x i8> %80, ptr %81, align 1, !tbaa !5, !alias.scope !16, !noalias !13
  store <16 x i8> zeroinitializer, ptr %77, align 1, !tbaa !5, !alias.scope !13
  store <16 x i8> zeroinitializer, ptr %79, align 1, !tbaa !5, !alias.scope !13
  %82 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 64
  %83 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 64
  %84 = load <16 x i8>, ptr %83, align 1, !tbaa !5, !alias.scope !13
  %85 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 80
  %86 = load <16 x i8>, ptr %85, align 1, !tbaa !5, !alias.scope !13
  store <16 x i8> %84, ptr %82, align 1, !tbaa !5, !alias.scope !16, !noalias !13
  %87 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 80
  store <16 x i8> %86, ptr %87, align 1, !tbaa !5, !alias.scope !16, !noalias !13
  store <16 x i8> zeroinitializer, ptr %83, align 1, !tbaa !5, !alias.scope !13
  store <16 x i8> zeroinitializer, ptr %85, align 1, !tbaa !5, !alias.scope !13
  %88 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 96
  %89 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 96
  %90 = load <16 x i8>, ptr %89, align 1, !tbaa !5, !alias.scope !13
  %91 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 112
  %92 = load <16 x i8>, ptr %91, align 1, !tbaa !5, !alias.scope !13
  store <16 x i8> %90, ptr %88, align 1, !tbaa !5, !alias.scope !16, !noalias !13
  %93 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 112
  store <16 x i8> %92, ptr %93, align 1, !tbaa !5, !alias.scope !16, !noalias !13
  store <16 x i8> zeroinitializer, ptr %89, align 1, !tbaa !5, !alias.scope !13
  store <16 x i8> zeroinitializer, ptr %91, align 1, !tbaa !5, !alias.scope !13
  %94 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 128
  %95 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 128
  %96 = load <16 x i8>, ptr %95, align 1, !tbaa !5, !alias.scope !13
  %97 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 144
  %98 = load <16 x i8>, ptr %97, align 1, !tbaa !5, !alias.scope !13
  store <16 x i8> %96, ptr %94, align 1, !tbaa !5, !alias.scope !16, !noalias !13
  %99 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 144
  store <16 x i8> %98, ptr %99, align 1, !tbaa !5, !alias.scope !16, !noalias !13
  store <16 x i8> zeroinitializer, ptr %95, align 1, !tbaa !5, !alias.scope !13
  store <16 x i8> zeroinitializer, ptr %97, align 1, !tbaa !5, !alias.scope !13
  %100 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 160
  %101 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 160
  %102 = load <16 x i8>, ptr %101, align 1, !tbaa !5, !alias.scope !13
  %103 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 176
  %104 = load <16 x i8>, ptr %103, align 1, !tbaa !5, !alias.scope !13
  store <16 x i8> %102, ptr %100, align 1, !tbaa !5, !alias.scope !16, !noalias !13
  %105 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 176
  store <16 x i8> %104, ptr %105, align 1, !tbaa !5, !alias.scope !16, !noalias !13
  store <16 x i8> zeroinitializer, ptr %101, align 1, !tbaa !5, !alias.scope !13
  store <16 x i8> zeroinitializer, ptr %103, align 1, !tbaa !5, !alias.scope !13
  %106 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 192
  %107 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 192
  %108 = load <16 x i8>, ptr %107, align 1, !tbaa !5, !alias.scope !13
  %109 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 208
  %110 = load <16 x i8>, ptr %109, align 1, !tbaa !5, !alias.scope !13
  store <16 x i8> %108, ptr %106, align 1, !tbaa !5, !alias.scope !16, !noalias !13
  %111 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 208
  store <16 x i8> %110, ptr %111, align 1, !tbaa !5, !alias.scope !16, !noalias !13
  store <16 x i8> zeroinitializer, ptr %107, align 1, !tbaa !5, !alias.scope !13
  store <16 x i8> zeroinitializer, ptr %109, align 1, !tbaa !5, !alias.scope !13
  %112 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 224
  %113 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 224
  %114 = load <16 x i8>, ptr %113, align 1, !tbaa !5, !alias.scope !13
  %115 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 240
  %116 = load <16 x i8>, ptr %115, align 1, !tbaa !5, !alias.scope !13
  store <16 x i8> %114, ptr %112, align 1, !tbaa !5, !alias.scope !16, !noalias !13
  %117 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 240
  store <16 x i8> %116, ptr %117, align 1, !tbaa !5, !alias.scope !16, !noalias !13
  store <16 x i8> zeroinitializer, ptr %113, align 1, !tbaa !5, !alias.scope !13
  store <16 x i8> zeroinitializer, ptr %115, align 1, !tbaa !5, !alias.scope !13
  br label %119

118:                                              ; preds = %119
  ret void

119:                                              ; preds = %122, %69
  %120 = add nuw nsw i64 %59, 1
  %121 = icmp eq i64 %120, 512
  br i1 %121, label %118, label %58, !llvm.loop !18

122:                                              ; preds = %58, %122
  %123 = phi i64 [ %131, %122 ], [ 0, %58 ]
  %124 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 %123
  %125 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 %123
  %126 = load i8, ptr %125, align 1, !tbaa !5
  store i8 %126, ptr %124, align 1, !tbaa !5
  store i8 0, ptr %125, align 1, !tbaa !5
  %127 = or i64 %123, 1
  %128 = getelementptr inbounds [256 x i8], ptr %1, i64 %59, i64 %127
  %129 = getelementptr inbounds [256 x i8], ptr %2, i64 %59, i64 %127
  %130 = load i8, ptr %129, align 1, !tbaa !5
  store i8 %130, ptr %128, align 1, !tbaa !5
  store i8 0, ptr %129, align 1, !tbaa !5
  %131 = add nuw nsw i64 %123, 2
  %132 = icmp eq i64 %131, 256
  br i1 %132, label %119, label %122, !llvm.loop !19
}

; Function Attrs: nounwind uwtable
define dso_local void @app() local_unnamed_addr #2 {
  %1 = alloca [512 x [256 x i8]], align 16
  %2 = alloca [512 x [256 x i8]], align 16
  call void @llvm.lifetime.start.p0(i64 131072, ptr nonnull %1) #7
  call void @llvm.memset.p0.i64(ptr noundef nonnull align 16 dereferenceable(131072) %1, i8 0, i64 131072, i1 false), !tbaa !5
  %3 = getelementptr inbounds [256 x i8], ptr %1, i64 1, i64 6
  store i8 1, ptr %3, align 2, !tbaa !5
  %4 = getelementptr inbounds [256 x i8], ptr %1, i64 1, i64 7
  store i8 1, ptr %4, align 1, !tbaa !5
  %5 = getelementptr inbounds [256 x i8], ptr %1, i64 2, i64 6
  store i8 1, ptr %5, align 2, !tbaa !5
  %6 = getelementptr inbounds [256 x i8], ptr %1, i64 2, i64 7
  store i8 1, ptr %6, align 1, !tbaa !5
  %7 = getelementptr inbounds [256 x i8], ptr %1, i64 11, i64 6
  store i8 1, ptr %7, align 2, !tbaa !5
  %8 = getelementptr inbounds [256 x i8], ptr %1, i64 11, i64 7
  store i8 1, ptr %8, align 1, !tbaa !5
  %9 = getelementptr inbounds [256 x i8], ptr %1, i64 11, i64 8
  store i8 1, ptr %9, align 8, !tbaa !5
  %10 = getelementptr inbounds [256 x i8], ptr %1, i64 12, i64 5
  store i8 1, ptr %10, align 1, !tbaa !5
  %11 = getelementptr inbounds [256 x i8], ptr %1, i64 12, i64 9
  store i8 1, ptr %11, align 1, !tbaa !5
  %12 = getelementptr inbounds [256 x i8], ptr %1, i64 13, i64 4
  store i8 1, ptr %12, align 4, !tbaa !5
  %13 = getelementptr inbounds [256 x i8], ptr %1, i64 13, i64 10
  store i8 1, ptr %13, align 2, !tbaa !5
  %14 = getelementptr inbounds [256 x i8], ptr %1, i64 14, i64 4
  store i8 1, ptr %14, align 4, !tbaa !5
  %15 = getelementptr inbounds [256 x i8], ptr %1, i64 14, i64 10
  store i8 1, ptr %15, align 2, !tbaa !5
  %16 = getelementptr inbounds [256 x i8], ptr %1, i64 15, i64 7
  store i8 1, ptr %16, align 1, !tbaa !5
  %17 = getelementptr inbounds [256 x i8], ptr %1, i64 16, i64 5
  store i8 1, ptr %17, align 1, !tbaa !5
  %18 = getelementptr inbounds [256 x i8], ptr %1, i64 16, i64 9
  store i8 1, ptr %18, align 1, !tbaa !5
  %19 = getelementptr inbounds [256 x i8], ptr %1, i64 17, i64 6
  store i8 1, ptr %19, align 2, !tbaa !5
  %20 = getelementptr inbounds [256 x i8], ptr %1, i64 17, i64 7
  store i8 1, ptr %20, align 1, !tbaa !5
  %21 = getelementptr inbounds [256 x i8], ptr %1, i64 17, i64 8
  store i8 1, ptr %21, align 8, !tbaa !5
  %22 = getelementptr inbounds [256 x i8], ptr %1, i64 18, i64 7
  store i8 1, ptr %22, align 1, !tbaa !5
  %23 = getelementptr inbounds [256 x i8], ptr %1, i64 21, i64 6
  store i8 1, ptr %23, align 2, !tbaa !5
  %24 = getelementptr inbounds [256 x i8], ptr %1, i64 21, i64 5
  store i8 1, ptr %24, align 1, !tbaa !5
  %25 = getelementptr inbounds [256 x i8], ptr %1, i64 21, i64 4
  store i8 1, ptr %25, align 4, !tbaa !5
  %26 = getelementptr inbounds [256 x i8], ptr %1, i64 22, i64 6
  store i8 1, ptr %26, align 2, !tbaa !5
  %27 = getelementptr inbounds [256 x i8], ptr %1, i64 22, i64 5
  store i8 1, ptr %27, align 1, !tbaa !5
  %28 = getelementptr inbounds [256 x i8], ptr %1, i64 22, i64 4
  store i8 1, ptr %28, align 4, !tbaa !5
  %29 = getelementptr inbounds [256 x i8], ptr %1, i64 23, i64 3
  store i8 1, ptr %29, align 1, !tbaa !5
  %30 = getelementptr inbounds [256 x i8], ptr %1, i64 23, i64 7
  store i8 1, ptr %30, align 1, !tbaa !5
  %31 = getelementptr inbounds [256 x i8], ptr %1, i64 25, i64 2
  store i8 1, ptr %31, align 2, !tbaa !5
  %32 = getelementptr inbounds [256 x i8], ptr %1, i64 25, i64 3
  store i8 1, ptr %32, align 1, !tbaa !5
  %33 = getelementptr inbounds [256 x i8], ptr %1, i64 25, i64 7
  store i8 1, ptr %33, align 1, !tbaa !5
  %34 = getelementptr inbounds [256 x i8], ptr %1, i64 25, i64 8
  store i8 1, ptr %34, align 8, !tbaa !5
  %35 = getelementptr inbounds [256 x i8], ptr %1, i64 35, i64 4
  store i8 1, ptr %35, align 4, !tbaa !5
  %36 = getelementptr inbounds [256 x i8], ptr %1, i64 35, i64 5
  store i8 1, ptr %36, align 1, !tbaa !5
  %37 = getelementptr inbounds [256 x i8], ptr %1, i64 36, i64 4
  store i8 1, ptr %37, align 4, !tbaa !5
  %38 = getelementptr inbounds [256 x i8], ptr %1, i64 36, i64 5
  store i8 1, ptr %38, align 1, !tbaa !5
  call void @llvm.lifetime.start.p0(i64 131072, ptr nonnull %2) #7
  call void @llvm.memset.p0.i64(ptr noundef nonnull align 16 dereferenceable(131072) %2, i8 0, i64 131072, i1 false), !tbaa !5
  br label %39

39:                                               ; preds = %45, %0
  %40 = phi i64 [ 0, %0 ], [ %46, %45 ]
  %41 = trunc i64 %40 to i32
  br label %47

42:                                               ; preds = %47
  %43 = add nuw nsw i64 %40, 1
  %44 = icmp eq i64 %43, 512
  br i1 %44, label %56, label %45

45:                                               ; preds = %42, %56
  %46 = phi i64 [ %43, %42 ], [ 0, %56 ]
  br label %39, !llvm.loop !21

47:                                               ; preds = %47, %39
  %48 = phi i64 [ 0, %39 ], [ %54, %47 ]
  %49 = getelementptr inbounds [256 x i8], ptr %1, i64 %40, i64 %48
  %50 = load i8, ptr %49, align 1, !tbaa !5
  %51 = icmp ne i8 %50, 1
  %52 = trunc i64 %48 to i32
  %53 = sext i1 %51 to i32
  tail call void @simPutPixel(i32 noundef %41, i32 noundef %52, i32 noundef %53) #7
  %54 = add nuw nsw i64 %48, 1
  %55 = icmp eq i64 %54, 256
  br i1 %55, label %42, label %47, !llvm.loop !10

56:                                               ; preds = %42
  tail call void (...) @simFlush() #7
  call void @next_generation(ptr poison, ptr noundef nonnull %1, ptr noundef nonnull %2)
  br label %45
}

; Function Attrs: argmemonly nocallback nofree nounwind willreturn writeonly
declare void @llvm.memset.p0.i64(ptr nocapture writeonly, i8, i64, i1 immarg) #6

attributes #0 = { argmemonly nofree norecurse nosync nounwind writeonly uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { argmemonly mustprogress nocallback nofree nosync nounwind willreturn }
attributes #2 = { nounwind uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { mustprogress nofree norecurse nosync nounwind readnone willreturn uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #5 = { argmemonly nofree norecurse nosync nounwind uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #6 = { argmemonly nocallback nofree nounwind willreturn writeonly }
attributes #7 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{!"Ubuntu clang version 15.0.7"}
!5 = !{!6, !6, i64 0}
!6 = !{!"omnipotent char", !7, i64 0}
!7 = !{!"Simple C/C++ TBAA"}
!8 = distinct !{!8, !9}
!9 = !{!"llvm.loop.mustprogress"}
!10 = distinct !{!10, !9}
!11 = distinct !{!11, !9}
!12 = distinct !{!12, !9}
!13 = !{!14}
!14 = distinct !{!14, !15}
!15 = distinct !{!15, !"LVerDomain"}
!16 = !{!17}
!17 = distinct !{!17, !15}
!18 = distinct !{!18, !9}
!19 = distinct !{!19, !9, !20}
!20 = !{!"llvm.loop.isvectorized", i32 1}
!21 = distinct !{!21, !9}
